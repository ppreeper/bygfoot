#include "cup.h"
#include "fixture.h"
#include "free.h"
#include "game_gui.h"
#include "league.h"
#include "live_game.h"
#include "maths.h"
#include "misc.h"
#include "option.h"
#include "player.h"
#include "team.h"
#include "transfer.h"
#include "treeview.h"
#include "user.h"
#include "window.h"

/** Create a new user with default values. */
User
user_new(void)
{
    User new;

    new.name = g_string_new("NONAME");
    new.tm = NULL;
    new.team_id = -1;
    
    live_game_reset(&new.live_game, NULL, FALSE);

    new.events = g_array_new(FALSE, FALSE, sizeof(Event)); 
    new.history = g_array_new(FALSE, FALSE, sizeof(UserHistory)); 
    new.options.list = NULL;
    new.options.datalist = NULL;

    return new;
}

/** Move a user's team to top or bottom league
    at the beginning of a new game and set up the team.
    @param user The user we set up the team for. */
void
user_set_up_team_new_game(User *user)
{
    gchar buf[SMALL];
    gint rndom, max, lig_idx = -1;

    if(user->scout == 0)
	user_set_up_team(user);
    else
    {
	if(user->scout == 1 &&
	   lig(0).id != user->tm->clid)
	    lig_idx = 0;
	else if(lig(ligs->len - 1).id != user->tm->clid)
	    lig_idx = ligs->len - 1;

	max = lig(lig_idx).teams->len - 1;
	rndom = math_rndi(0, max);
	sprintf(buf, "%s", g_array_index(lig(lig_idx).teams, Team, rndom).name->str);
	g_string_printf(g_array_index(lig(lig_idx).teams, Team, rndom).name, "%s",
			user->tm->name->str);
	g_string_printf(user->tm->name, "%s", buf);

	user->tm = &g_array_index(lig(lig_idx).teams, Team, rndom);
	user->team_id = g_array_index(lig(lig_idx).teams, Team, rndom).id;

	user_set_up_team(user);
    }
}

/** Set up finances, remove some players etc. for a new user team.
    @param user The user whose team we set up. */
void
user_set_up_team(User *user)
{
    gint i, j;

    for(i=PLAYER_POS_DEFENDER; i<=PLAYER_POS_FORWARD; i++)
	for(j=user->tm->players->len - 1; j > 10; j--)
	    if(g_array_index(user->tm->players, Player, j).pos == i)
	    {
		player_remove_from_team(user->tm, j);
		break;
	    }

    user->scout = user->physio = QUALITY_AVERAGE;
    
    user->tm->style = 0;
    
    user_set_up_finances(user);
    user_set_up_counters(user);
}


/** Set the counters of the user to their initial values. */
void
user_set_up_counters(User *user)
{
    gint i;

    for(i=0;i<COUNT_USER_END;i++)
	user->counters[i] = 0;

    user->counters[COUNT_USER_LOAN] =
	user->counters[COUNT_USER_POSITIVE] = -1;
}
/** Set up the user's finances when he's got a new team.
    @param user The user we set up the finances for. */
void
user_set_up_finances(User *user)
{
    gint i;

    for(i=0; i<MON_OUT_END;i++)
	user->money_out[0][i] = user->money_out[1][i] = 0;
    for(i=0; i<MON_IN_END;i++)
	user->money_in[0][i] = user->money_in[1][i] = 0;
    
    user->debt = 0;
    user->money = 
	math_round_integer(user->tm->stadium.capacity * 
			   math_rndi(const_int("int_initial_money_lower"),
				     const_int("int_initial_money_upper")), 2);
}

/** Remove a user from the game.
    @param idx The index of the user in the #users array.
    @param regenerate_team Whether the user's team has to be
    regenerated. */
void
user_remove(gint idx, gboolean regenerate_team)
{
    gint i;

    if(regenerate_team)
    {
	for(i=0;i<usr(idx).tm->players->len;i++)
	    free_player(&g_array_index(usr(idx).tm->players, Player, i));

	team_generate_players_stadium(usr(idx).tm);
    }

    free_user(&usr(idx));
    g_array_remove_index(users, idx);
}

void
user_set_player_list_attributes(const User *user, PlayerListAttribute *attribute, gint list_number)
{
    gint i, cnt = 0;
    gchar prefix[SMALL];

    sprintf(prefix, "int_opt_user_pl%d_att", list_number);

    for(i=0;i<user->options.list->len;i++)
	if(g_str_has_prefix(g_array_index(user->options.list, Option, i).name->str, prefix))
	{
	    attribute->on_off[cnt] = g_array_index(user->options.list, Option, i).value;
	    cnt++;
	}
}

/** Find out whether there are user games at the specified date. */
gboolean
query_user_games_in_week_round(gint week_number, gint week_round_number)
{
    gint i;

    for(i=0;i<users->len;i++)
	if(query_user_game_in_week_round(i, week_number, week_round_number))
	    return TRUE;

    return FALSE;
}

/** Find out whether the specified user has a match at the specified date. */
gboolean
query_user_game_in_week_round(gint usr_idx, gint week_number, gint week_round_number)
{
    gint i, j;

    if(week_round_number == 1)
    {
	for(i=0;i<ligs->len;i++)
	    for(j=0;j<lig(i).fixtures->len;j++)
		if(fixture_user_team_involved(&g_array_index(lig(i).fixtures, Fixture, j)) == usr_idx &&
		   g_array_index(lig(i).fixtures, Fixture, j).week_number == week_number &&
		   g_array_index(lig(i).fixtures, Fixture, j).week_round_number == week_round_number)
		    return TRUE;
    }
    else
    {
	for(i=0;i<cps->len;i++)
	    for(j=0;j<cp(i).fixtures->len;j++)
		if(fixture_user_team_involved(&g_array_index(cp(i).fixtures, Fixture, j)) == usr_idx &&
		   g_array_index(cp(i).fixtures, Fixture, j).week_number == week_number &&
		   g_array_index(cp(i).fixtures, Fixture, j).week_round_number == week_round_number)
		    return TRUE;
    }

    return FALSE;
}


/** Get the user managing the team.
    @param tm The team.
    @return A pointer to the user. */
User*
user_from_team(const Team *tm)
{
    gint i;

    for(i=0;i<users->len;i++)
	if(usr(i).tm == tm)
	    return &usr(i);

    g_warning("User going with team %s not found.\n",
	      tm->name->str);

    return NULL;
}

/** Update the counters of the users. */
void
user_weekly_update_counters(User *user)
{
    gint *cnts = user->counters;
    gint increase_capacity;
    gfloat increase_safety;

    if(cnts[COUNT_USER_STADIUM_CAPACITY] > 0)
    {
	increase_capacity = math_rndi(const_int("int_stadium_improvement_base_seats") - 
				      const_int("int_stadium_improvement_seats_variance"),
				      const_int("int_stadium_improvement_base_seats") + 
				      const_int("int_stadium_improvement_seats_variance"));
	user->tm->stadium.capacity += MIN(cnts[COUNT_USER_STADIUM_CAPACITY],
					  increase_capacity);
	cnts[COUNT_USER_STADIUM_CAPACITY] = 
	    MAX(cnts[COUNT_USER_STADIUM_CAPACITY] - increase_capacity, 0);
    }

    if(cnts[COUNT_USER_STADIUM_SAFETY] > 0)
    {
	increase_safety = math_rnd(const_float("float_stadium_improvement_base_safety") - 
				   const_float("float_stadium_improvement_safety_variance"),
				   const_float("float_stadium_improvement_base_safety") + 
				   const_float("float_stadium_improvement_safety_variance"));
	user->tm->stadium.safety += MIN((gfloat)cnts[COUNT_USER_STADIUM_SAFETY] / 100,
					increase_safety);
	user->tm->stadium.safety = MIN(user->tm->stadium.safety, 1);

	cnts[COUNT_USER_STADIUM_SAFETY] = 
	    MAX(cnts[COUNT_USER_STADIUM_SAFETY] - (gint)rint(increase_safety * 100), 0);
    }
}

/** Return a default new user event. */
Event
user_event_new(void)
{
    Event new;

    new.user = NULL;
    new.type = -1;
    new.value1 = new.value2 = -1;
    new.value_pointer = NULL;
    new.value_string = NULL;

    return new;
}

/** Add an event with the specified values to the event array of the user. */
void
user_event_add(User *user, gint type, gint value1, gint value2, 
	       gpointer value_pointer, gchar *value_string)
{
    Event new = user_event_new();

    new.user = user;
    new.type = type;
    new.value1 = value1;
    new.value2 = value2;
    new.value_pointer = value_pointer;
    
    if(value_string != NULL)
	new.value_string = g_string_new(value_string);
    else
	new.value_string = NULL;    

    g_array_append_val(user->events, new);
}

/** Remove an event from the user event array.
    @param user The user.
    @param idx The index of the event in the array. */
void
user_event_remove(User *user, gint idx)
{
    free_event(&g_array_index(user->events, Event, idx));
    g_array_remove_index(user->events, idx);
}

/** Find the event index going with the values. */
gint
user_event_get_index(User *user, gint type, gint value1, gint value2, 
		     gpointer value_pointer, gchar *value_string)
{
    gint i;

    for(i=0;i<user->events->len;i++)
	if(g_array_index(user->events, Event, i).type == type &&
	   g_array_index(user->events, Event, i).value1 == value1 &&
	   g_array_index(user->events, Event, i).value2 == value2 &&
	   g_array_index(user->events, Event, i).value_pointer == value_pointer &&
	   ((gpointer)g_array_index(user->events, Event, i).value_string == (gpointer)value_string ||
	    strcmp(g_array_index(user->events, Event, i).value_string->str, value_string) == 0))
	    return i;

    g_warning("user_event_get_index: didn't find index.");

    return -1;
}
		     

/** Show the next event for the current user. */
void
user_event_show_next(void)
{    
    Event *event = NULL;
    gchar buf[BIG],
	buf2[SMALL], buf3[SMALL];
    gint temp_int = -1;

    if(current_user.events->len == 0)
	return;

    stat1 = STATUS_SHOW_EVENT;

    event = &g_array_index(current_user.events, Event, 0);

    switch(event->type)
    {
	default:
	    g_warning("user_event_show_next: unknown event type %d\n", event->type);
	    break;
	case EVENT_TYPE_PLAYER_LEFT:
	    sprintf(buf, _("%s has left your team because his contract expired."),
		    event->value_string->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_WARNING:
	    game_gui_show_warning(event->value_string->str);
	    break;
	case EVENT_TYPE_FIRE_FINANCE:
	    stat0 = STATUS_JOB_OFFER_FIRE_FINANCE;
	    statp = event->value_pointer;
	    game_gui_show_job_offer((Team*)event->value_pointer, STATUS_JOB_OFFER_FIRE_FINANCE);
	    break;
	case EVENT_TYPE_OVERDRAW:
	    if(event->value1 == 1)
		sprintf(buf, _("You have overdrawn your bank account. The team owners give you %d weeks to get above your drawing credit limit."), const_int("int_finance_overdraw_positive"));
	    else
		sprintf(buf, _("You have overdrawn your bank account once again. Bear in mind that after the fourth time you get fired.\nThe team owners give you %d weeks to get above your drawing credit limit."), const_int("int_finance_overdraw_positive"));
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER_REJECTED:
	    sprintf(buf, _("The owners of %s have rejected your offer for %s. Either the fee or the wage you suggested was too low, apparently."), ((Team*)event->value_pointer)->name->str, event->value_string->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER_MONEY:
	    sprintf(buf, _("You didn't have enough money to buy %s from %s."),
		    event->value_string->str, ((Team*)event->value_pointer)->name->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER_ROSTER:
	    sprintf(buf, _("Your roster is full. You couldn't buy %s from %s."),
		    event->value_string->str, ((Team*)event->value_pointer)->name->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER_ACCEPTED:
	    sprintf(buf, _("Congratulations! The owners of %s have accepted your offer for %s!"),
		    ((Team*)event->value_pointer)->name->str, event->value_string->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER:
	    temp_int = transfer_get_index(event->user->tm, event->value1);
	    misc_print_grouped_int(transoff(temp_int, 0).fee, buf2, FALSE);
	    misc_print_grouped_int(ABS(transoff(temp_int, 0).fee - 
				       player_of_id_team(event->user->tm, trans(temp_int).id)->value), buf3, FALSE);
	    if(transoff(temp_int, 0).fee - 
	       player_of_id_team(event->user->tm, trans(temp_int).id)->value > 0)
		strcat(buf3, " more");
	    else
		strcat(buf3, " less");

	    sprintf(buf, _("%s would like to buy %s. They offer %s for him, which is %s than the player's value. Do you accept?"), transoff(temp_int, 0).tm->name->str,
		    player_of_id_team(event->user->tm, trans(temp_int).id)->name->str,
		    buf2, buf3);
	    stat1 = STATUS_TRANSFER_OFFER;
	    stat2 = temp_int;
	    window_show_yesno(buf);
	    break;
	case EVENT_TYPE_TRANSFER_OFFER_OUTBID:
	    sprintf(buf, _("There was a higher bid for %s than yours."),
		    event->value_string->str);
	    game_gui_show_warning(buf);
	    break;
	case EVENT_TYPE_PLAYER_CAREER_STOP:
	    sprintf(buf, _("%s's injury was so severe that he can't play football on a professional level anymore. He leaves your team."), player_of_id_team(event->user->tm, event->value1)->name->str);
	    if(event->user->tm->players->len < 12)
	    {
		strcat(buf, _(" Fortunately he's got a cousin who can help your team out."));
		player_replace_by_new(player_of_id_team(event->user->tm, event->value1), TRUE);
	    }
	    else
		player_remove_from_team(event->user->tm, player_id_index(event->user->tm, event->value1));
	    treeview_show_user_player_list();
	    game_gui_show_warning(buf);
	    break;
    }

    user_event_remove(&current_user, 0);
}

/** Change the team of a user. */
void
user_change_team(User *user, Team *tm)
{
    gint i;

    user->tm = tm;
    user->team_id = tm->id;

    user_set_up_team(user);
    for(i=user->events->len - 1; i >= 0; i--)
	user_event_remove(user, i);    
}

/** Return the index of the user in the users array. */
gint
user_get_index(User *user)
{ 
    gint i;

    for(i=0;i<users->len;i++)
	if(&usr(i) == user)
	    return i;

    g_warning("user_get_index: user not found.\n");
    
    return -1;
}

/** Check whether one of the user teams has an unfit player
    in the startup formation. */
gboolean
query_user_teams_have_unfit(void)
{
    gint i, j;

    for(i=0;i<users->len;i++)
    {
	if(query_user_game_in_week_round(i, week, week_round))
	{
	    for(j=0;j<11;j++)
		if(g_array_index(usr(i).tm->players, Player, j).health != 0 ||
		   player_is_banned(&g_array_index(usr(i).tm->players, Player, j)) > 0)
		    return TRUE;
	}
    }

    return FALSE;
}

/** Compare function for history sorting. */
gint
user_history_compare(gconstpointer a, gconstpointer b)
{
    gint return_value = 0;
    const UserHistory *his1 = (const UserHistory*)a,
	*his2 = (const UserHistory*)b;

    if(his1->season < his2->season)
	return_value = 1;
    else if(his1->season > his2->season)
	return_value = -1;
    else if(his1->week < his2->week)
	return_value = 1;
    else if(his1->week > his2->week)
	return_value = -1;

    return return_value;
}

/** Add an element to the user history filled with the given values. */
void
user_history_add(User *user, gint type, gint team_id,
		 gint value1, gint value2, gchar *string)
{
    gint i;
    UserHistory new_history;
    UserHistory *his = &new_history;
    gboolean replace = FALSE;


    if(type == USER_HISTORY_WIN_FINAL ||
       type == USER_HISTORY_LOSE_FINAL ||
       type == USER_HISTORY_REACH_CUP_ROUND)
    {
	for(i=0;i<user->history->len;i++)
	    if((g_array_index(user->history, UserHistory, i).type == USER_HISTORY_WIN_FINAL ||
		g_array_index(user->history, UserHistory, i).type == USER_HISTORY_LOSE_FINAL ||
		g_array_index(user->history, UserHistory, i).type == USER_HISTORY_REACH_CUP_ROUND) &&
	       g_array_index(user->history, UserHistory, i).season == season &&
	       g_array_index(user->history, UserHistory, i).team_id == team_id &&
	       g_array_index(user->history, UserHistory, i).value1 == value1)
	    {
		/** Same cup round. */
		if(g_array_index(user->history, UserHistory, i).value2 == value2 &&
		   type == USER_HISTORY_REACH_CUP_ROUND)
		    return;

		his = &g_array_index(user->history, UserHistory, i);
		replace = TRUE;
		break;
	    }
    }

    his->season = season;
    his->week = week;

    his->type = type;
    his->team_id = team_id;
    his->value1 = value1;
    his->value2 = value2;
    
    if(replace)
    {
	g_string_printf(his->value_string, "%s", string);
	g_array_sort(user->history, (GCompareFunc)user_history_compare);
    }
    else
    {
	his->value_string = g_string_new(string);
	g_array_prepend_val(user->history, *his);
    }
}

/** Write the text corresponding to the history event
    into the buffer. */
void
user_history_to_string(const UserHistory *history, gchar *buf)
{
    gchar buf2[SMALL];

    switch(history->type)
    {
	default:
	    g_warning("user_history_to_string: unknown history type %d.\n", history->type);
	    strcpy(buf, "FIXME!!!");
	case USER_HISTORY_START_GAME:
	    sprintf(buf, "You start the game with %s in the %s.",
		    team_of_id(history->team_id)->name->str,
		    league_cup_get_name_string(history->value1));
	    break;
    	case USER_HISTORY_FIRE_FINANCES:
	    sprintf(buf, "%s fires you because of financial mismanagement.\nYou find a new job with %s in the %s.",
		    team_of_id(history->team_id)->name->str,
		    team_of_id(history->value1)->name->str,
		    league_cup_get_name_string(history->value2));
	    break;
    	case  USER_HISTORY_FIRE_FAILURE:
	    sprintf(buf, "%s fires you because of unsuccessfulness.\nYou find a new job with %s in the %s.",
		    team_of_id(history->team_id)->name->str,
		    team_of_id(history->value1)->name->str,
		    league_cup_get_name_string(history->value2));
	    break;
    	case  USER_HISTORY_JOB_OFFER_ACCEPTED:
	    sprintf(buf, "%s offer you a job in the %s.\nYou accept the challenge and leave %s.",
		    team_of_id(history->value1)->name->str,
		    league_cup_get_name_string(history->value2),
		    team_of_id(history->team_id)->name->str);
	    break;
    	case  USER_HISTORY_END_SEASON:
	    sprintf(buf, "You finish the season in %s on rank %d.",
		    league_cup_get_name_string(history->value1),
		    history->value2);
	    break;
    	case  USER_HISTORY_PROMOTED:
	    sprintf(buf, "You get promoted to the %s.",
		    league_cup_get_name_string(history->value1));
	    break;	    
    	case  USER_HISTORY_RELEGATED:
	    sprintf(buf, "You get relegated to the %s.",
		    league_cup_get_name_string(history->value1));
	    break;	    
    	case  USER_HISTORY_WIN_FINAL:
	    sprintf(buf, "You win the %s final against %s.",
		    league_cup_get_name_string(history->value1),
		    history->value_string->str);
	    break;
    	case  USER_HISTORY_LOSE_FINAL:
	    sprintf(buf, "You lose in the %s final against %s.",
		    league_cup_get_name_string(history->value1),
		    history->value_string->str);
	    break;
    	case USER_HISTORY_REACH_CUP_ROUND:	    
	    cup_get_round_name(cup_from_clid(history->value1), history->value2, buf2);
	    sprintf(buf, "You reach the %s (round %d) of the %s.", buf2,
		    history->value2 + 1,
		    league_cup_get_name_string(history->value1));
	    break;
    	case USER_HISTORY_CHAMPION:	    
	    sprintf(buf, "You are champion of the %s!",
		    league_cup_get_name_string(history->value1));
	    break;
    }
}
