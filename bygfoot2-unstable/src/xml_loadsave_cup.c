#include "cup.h"
#include "file.h"
#include "misc.h"
#include "team.h"
#include "xml.h"
#include "xml_loadsave_cup.h"
#include "xml_loadsave_fixtures.h"
#include "xml_loadsave_table.h"
#include "xml_loadsave_teams.h"

enum
{
    TAG_CUP = TAG_START_CUP,
    TAG_CUP_TYPE,
    TAG_CUP_LAST_WEEK,
    TAG_CUP_SKILL_DIFF,    
    TAG_CUP_CHOOSE_TEAM_USER,
    TAG_CUP_CHOOSE_TEAM,
    TAG_CUP_CHOOSE_TEAM_SID,
    TAG_CUP_CHOOSE_TEAM_NUMBER_OF_TEAMS,
    TAG_CUP_CHOOSE_TEAM_START_IDX,
    TAG_CUP_CHOOSE_TEAM_END_IDX,
    TAG_CUP_CHOOSE_TEAM_RANDOMLY,
    TAG_CUP_ROUND,
    TAG_CUP_ROUND_HOME_AWAY,
    TAG_CUP_ROUND_REPLAY,
    TAG_CUP_ROUND_NEUTRAL,
    TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_GROUPS,
    TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_ADVANCE,
    TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_BEST_ADVANCE,
    TAG_CUP_BYE,
    TAG_CUP_USER_TEAM,
    TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK,
    TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK_ROUND,
    TAG_END
};

gint state, team_clid;
gboolean in_choose_team_user, in_bye;
Cup *new_cup;
CupChooseTeam new_choose_team;
CupRound new_round;

void
xml_loadsave_cup_start_element (GMarkupParseContext *context,
				const gchar         *element_name,
				const gchar        **attribute_names,
				const gchar        **attribute_values,
				gpointer             user_data,
				GError             **error)
{
    gint i;
    gint tag = xml_get_tag_from_name(element_name);
    gboolean valid_tag = FALSE;

    for(i=TAG_CUP;i<TAG_END;i++)
	if(tag == i)
	{
	    state = i;
	    valid_tag = TRUE;
	}

    for(i=TAG_NAME;i<=TAG_ROUND;i++)
	if(tag == i)
	{
	    state = i;
	    valid_tag = TRUE;
	}

    if(tag == TAG_CUP_CHOOSE_TEAM)
	new_choose_team = cup_choose_team_new();
    else if(tag == TAG_CUP_CHOOSE_TEAM_USER)
	in_choose_team_user = TRUE;
    else if(tag == TAG_CUP_BYE)
	in_bye = TRUE;
    else if(tag == TAG_CUP_ROUND)
	new_round = cup_round_new();

     if(!valid_tag)
	g_warning("xml_loadsave_cup_start_element: unknown tag: %s; I'm in state %d\n",
		  element_name, state);
}

void
xml_loadsave_cup_end_element    (GMarkupParseContext *context,
				 const gchar         *element_name,
				 gpointer             user_data,
				 GError             **error)
{
    gint tag = xml_get_tag_from_name(element_name);

    if(tag == TAG_NAME ||
       tag == TAG_SHORT_NAME ||
       tag == TAG_SYMBOL ||
       tag == TAG_SID ||
       tag == TAG_ID ||
       tag == TAG_YELLOW_RED ||
       tag == TAG_WEEK_GAP ||
       tag == TAG_CUP_LAST_WEEK ||
       tag == TAG_CUP_TYPE ||
       tag == TAG_CUP_SKILL_DIFF ||
       tag == TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK ||
       tag == TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK_ROUND ||
       tag == TAG_CUP_USER_TEAM ||
       tag == TAG_CUP_CHOOSE_TEAM_USER ||
       tag == TAG_CUP_ROUND ||
       tag == TAG_CUP_BYE)
    {
	state = TAG_CUP;
	if(tag == TAG_CUP_CHOOSE_TEAM_USER)
	    in_choose_team_user = FALSE;
	else if(tag == TAG_CUP_BYE)
	    in_bye = FALSE;
	else if(tag == TAG_CUP_ROUND)
	    g_array_append_val(new_cup->rounds, new_round);
    }
    else if(tag == TAG_CUP_CHOOSE_TEAM)
    {
	if(in_choose_team_user)
	{
	    state = TAG_CUP_CHOOSE_TEAM_USER;
	    new_cup->choose_team_user = new_choose_team;
	}
	else
	{
	    state = TAG_CUP;
	    g_array_append_val(new_cup->choose_teams, new_choose_team);
	}
    }
    else if(tag == TAG_TEAM_CLID ||
	    tag == TAG_TEAM_ID)
	state = (in_bye) ? TAG_CUP_BYE : TAG_CUP_USER_TEAM;
    else if(tag == TAG_CUP_CHOOSE_TEAM_NUMBER_OF_TEAMS ||
	    tag == TAG_CUP_CHOOSE_TEAM_START_IDX ||
	    tag == TAG_CUP_CHOOSE_TEAM_END_IDX ||
	    tag == TAG_CUP_CHOOSE_TEAM_SID ||
	    tag == TAG_CUP_CHOOSE_TEAM_RANDOMLY)
	state = TAG_CUP_CHOOSE_TEAM;
    else if(tag == TAG_CUP_ROUND_HOME_AWAY ||
	    tag == TAG_CUP_ROUND_REPLAY ||
	    tag == TAG_CUP_ROUND_NEUTRAL ||
	    tag == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_GROUPS ||
	    tag == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_ADVANCE ||
	    tag == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_BEST_ADVANCE)
	state = TAG_CUP_ROUND;
    else if(tag != TAG_CUP)
	g_warning("xml_loadsave_cup_end_element: unknown tag: %s; I'm in state %d\n",
		  element_name, state);
}

void
xml_loadsave_cup_text         (GMarkupParseContext *context,
			       const gchar         *text,
			       gsize                text_len,  
			       gpointer             user_data,
			       GError             **error)
{
    gchar buf[SMALL];
    gint int_value = -1;

    strncpy(buf, text, text_len);
    buf[text_len] = '\0';

    int_value = (gint)g_ascii_strtod(buf, NULL);

    if(state == TAG_NAME)
	g_string_printf(new_cup->name, "%s", buf);
    else if(state == TAG_SHORT_NAME)
	g_string_printf(new_cup->short_name, "%s", buf);
    else if(state == TAG_SYMBOL)
	g_string_printf(new_cup->symbol, "%s", buf);
    else if(state == TAG_SID)
	g_string_printf(new_cup->sid, "%s", buf);
    else if(state == TAG_ID)
	new_cup->id = int_value;
    else if(state == TAG_WEEK_GAP)
	new_cup->week_gap = int_value;
    else if(state == TAG_YELLOW_RED)
	new_cup->yellow_red = int_value;
    else if(state == TAG_CUP_TYPE)
	new_cup->type = int_value;
    else if(state == TAG_CUP_LAST_WEEK)
	new_cup->last_week = int_value;
    else if(state == TAG_CUP_SKILL_DIFF)
	new_cup->skill_diff = int_value;
    else if(state == TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK)
	new_cup->next_fixture_update_week = int_value;
    else if(state == TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK_ROUND)
	new_cup->next_fixture_update_week_round = int_value;
    else if(state == TAG_TEAM_CLID)
	team_clid = int_value;
    else if(state == TAG_TEAM_ID)
    {
	if(in_bye)
	    g_ptr_array_add(new_cup->bye, team_get_pointer_from_ids(team_clid, int_value));
	else
	    g_ptr_array_add(new_cup->user_teams, team_get_pointer_from_ids(team_clid, int_value));
    }
    else if(state == TAG_CUP_CHOOSE_TEAM_SID)
	g_string_printf(new_choose_team.sid, "%s", buf);
    else if(state == TAG_CUP_CHOOSE_TEAM_NUMBER_OF_TEAMS)
	new_choose_team.number_of_teams = int_value;
    else if(state == TAG_CUP_CHOOSE_TEAM_START_IDX)
	new_choose_team.start_idx = int_value;
    else if(state == TAG_CUP_CHOOSE_TEAM_END_IDX)
	new_choose_team.end_idx = int_value;
    else if(state == TAG_CUP_CHOOSE_TEAM_RANDOMLY)
	new_choose_team.randomly = int_value;
    else if(state == TAG_CUP_ROUND_HOME_AWAY)
	new_round.home_away = int_value;
    else if(state == TAG_CUP_ROUND_REPLAY)
	new_round.replay = int_value;
    else if(state == TAG_CUP_ROUND_NEUTRAL)
	new_round.neutral = int_value;
    else if(state == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_GROUPS)
	new_round.round_robin_number_of_groups = int_value;
    else if(state == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_ADVANCE)
	new_round.round_robin_number_of_advance = int_value;
    else if(state == TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_BEST_ADVANCE)
	new_round.round_robin_number_of_best_advance = int_value;
}

void
xml_loadsave_cup_read(const gchar *filename, Cup *cup)
{
    GMarkupParser parser = {xml_loadsave_cup_start_element,
			    xml_loadsave_cup_end_element,
			    xml_loadsave_cup_text, NULL, NULL};
    GMarkupParseContext *context;
    gchar *file_contents;
    guint length;
    GError *error = NULL;

    context = 
	g_markup_parse_context_new(&parser, 0, NULL, NULL);

    if(!g_file_get_contents(filename, &file_contents, &length, &error))
    {
	g_warning("xml_loadsave_cup_read: error reading file %s\n", filename);
	misc_print_error(&error, TRUE);
    }

    new_cup = cup;

    if(g_markup_parse_context_parse(context, file_contents, length, &error))
    {
	g_markup_parse_context_end_parse(context, NULL);
	g_markup_parse_context_free(context);
	g_free(file_contents);
    }
    else
    {
	g_warning("xml_loadsave_cup_read: error parsing file %s\n", filename);
	misc_print_error(&error, TRUE);
    }
}

void
xml_loadsave_cup_write(const gchar *prefix, const Cup *cup)
{
    gint i;
    gchar buf[SMALL];
    FILE *fil = NULL;

    for(i=0;i<cup->tables->len;i++)
    {
	sprintf(buf, "%s___cup_%d_table_%02d.xml", prefix, cup->id, i);
	xml_loadsave_table_write(buf, &g_array_index(cup->tables, Table, i));
    }

    sprintf(buf, "%s___cup_%d_fixtures.xml", prefix, cup->id);
    xml_loadsave_fixtures_write(buf, cup->fixtures);

    sprintf(buf, "%s___cup_%d.xml", prefix, cup->id);
    file_my_fopen(buf, "w", &fil, TRUE);

    fprintf(fil, "<_%d>\n", TAG_CUP);

    xml_write_g_string(fil, cup->name, TAG_NAME, I0);
    xml_write_g_string(fil, cup->short_name, TAG_SHORT_NAME, I0);
    xml_write_g_string(fil, cup->sid, TAG_SID, I0);
    xml_write_g_string(fil, cup->symbol, TAG_SYMBOL, I0);

    xml_write_int(fil, cup->id, TAG_ID, I0);
    xml_write_int(fil, cup->type, TAG_CUP_TYPE, I0);
    xml_write_int(fil, cup->last_week, TAG_CUP_LAST_WEEK, I0);
    xml_write_int(fil, cup->week_gap, TAG_WEEK_GAP, I0);
    xml_write_int(fil, cup->yellow_red, TAG_YELLOW_RED, I0);
    xml_write_int(fil, cup->skill_diff, TAG_CUP_SKILL_DIFF, I0);

    xml_write_int(fil, cup->next_fixture_update_week, 
		  TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK, I0);
    xml_write_int(fil, cup->next_fixture_update_week_round, 
		  TAG_CUP_NEXT_FIXTURE_UPDATE_WEEK_ROUND, I0);

    if(cup->type == CUP_TYPE_INTERNATIONAL)
    {
	sprintf(buf, "%s___cup_%d_teams.xml", prefix, cup->id);
	xml_loadsave_teams_write(buf, cup->teams);

	fprintf(fil, "<_%d>\n", TAG_CUP_CHOOSE_TEAM_USER);
	xml_loadsave_cup_write_choose_team(fil, &cup->choose_team_user);
	fprintf(fil, "</_%d>\n", TAG_CUP_CHOOSE_TEAM_USER);

	for(i=0;i<cup->user_teams->len;i++)
	{
	    fprintf(fil, "<_%d>\n", TAG_CUP_USER_TEAM);
	    xml_write_int(fil, ((Team*)g_ptr_array_index(cup->user_teams, i))->clid, 
			  TAG_TEAM_CLID, I1);
	    xml_write_int(fil, ((Team*)g_ptr_array_index(cup->user_teams, i))->id,
			  TAG_TEAM_ID, I1);
	    fprintf(fil, "</_%d>\n", TAG_CUP_USER_TEAM);
	}
    }

    for(i=0;i<cup->choose_teams->len;i++)
	xml_loadsave_cup_write_choose_team(fil,
	    &g_array_index(cup->choose_teams, CupChooseTeam, i));
	
    for(i=0;i<cup->rounds->len;i++)
	xml_loadsave_cup_write_round(fil,
	    &g_array_index(cup->rounds, CupRound, i));
    
    if(cup->bye != NULL)
	for(i=0;i<cup->bye->len;i++)
	{
	    fprintf(fil, "<_%d>\n", TAG_CUP_BYE);
	    xml_write_int(fil, ((Team*)g_ptr_array_index(cup->bye, i))->clid, 
			  TAG_TEAM_CLID, I1);
	    xml_write_int(fil, ((Team*)g_ptr_array_index(cup->bye, i))->id,
			  TAG_TEAM_ID, I1);
	    fprintf(fil, "</_%d>\n", TAG_CUP_BYE);
	}
    
    fprintf(fil, "</_%d>\n", TAG_CUP);

    fclose(fil);
}

void
xml_loadsave_cup_write_choose_team(FILE *fil, const CupChooseTeam *choose_team)
{
    fprintf(fil, "<_%d>\n", TAG_CUP_CHOOSE_TEAM);
    
    xml_write_g_string(fil, choose_team->sid, TAG_CUP_CHOOSE_TEAM_SID, I1);
    xml_write_int(fil, choose_team->number_of_teams, 
		  TAG_CUP_CHOOSE_TEAM_NUMBER_OF_TEAMS, I1);
    xml_write_int(fil, choose_team->start_idx, 
		  TAG_CUP_CHOOSE_TEAM_START_IDX, I1);
    xml_write_int(fil, choose_team->end_idx, 
		  TAG_CUP_CHOOSE_TEAM_END_IDX, I1);
    xml_write_int(fil, choose_team->randomly, 
		  TAG_CUP_CHOOSE_TEAM_RANDOMLY, I1);

    fprintf(fil, "</_%d>\n", TAG_CUP_CHOOSE_TEAM);
}

void
xml_loadsave_cup_write_round(FILE *fil, const CupRound *cup_round)
{
    fprintf(fil, "<_%d>\n", TAG_CUP_ROUND);

    xml_write_int(fil, cup_round->home_away,
		  TAG_CUP_ROUND_HOME_AWAY, I1);
    xml_write_int(fil, cup_round->replay,
		  TAG_CUP_ROUND_REPLAY, I1);
    xml_write_int(fil, cup_round->neutral,
		  TAG_CUP_ROUND_NEUTRAL, I1);
    xml_write_int(fil, cup_round->round_robin_number_of_groups,
		  TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_GROUPS, I1);
    xml_write_int(fil, cup_round->round_robin_number_of_advance,
		  TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_ADVANCE, I1);
    xml_write_int(fil, cup_round->round_robin_number_of_best_advance,
		  TAG_CUP_ROUND_ROUND_ROBIN_NUMBER_OF_BEST_ADVANCE, I1);

    fprintf(fil, "</_%d>\n", TAG_CUP_ROUND);
}