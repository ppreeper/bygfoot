#include "file.h"
#include "misc.h"
#include "xml.h"
#include "variables.h"
#include "xml_loadsave_misc.h"
#include "xml_loadsave_cup.h"
#include "xml_loadsave_league.h"

enum XmlLoadSaveCountryTags
{
    TAG_MISC = TAG_START_MISC,
    TAG_MISC_SEASON,
    TAG_MISC_WEEK,
    TAG_MISC_WEEK_ROUND,
    TAG_END
};

gint state;

void
xml_loadsave_misc_start_element (GMarkupParseContext *context,
				    const gchar         *element_name,
				    const gchar        **attribute_names,
				    const gchar        **attribute_values,
				    gpointer             user_data,
				    GError             **error)
{
    gint i;
    gint tag = xml_get_tag_from_name(element_name);
    gboolean valid_tag = FALSE;

    for(i=TAG_MISC;i<TAG_END;i++)
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

    if(!valid_tag)
	g_warning("xml_loadsave_misc_start_element: unknown tag: %s; I'm in state %d\n",
		  element_name, state);
}

void
xml_loadsave_misc_end_element    (GMarkupParseContext *context,
				     const gchar         *element_name,
				     gpointer             user_data,
				     GError             **error)
{
    gint tag = xml_get_tag_from_name(element_name);

    if(tag == TAG_NAME ||
       tag == TAG_SYMBOL ||
       tag == TAG_SID ||
       tag == TAG_MISC_SEASON ||
       tag == TAG_MISC_WEEK ||
       tag == TAG_MISC_WEEK_ROUND)
	state = TAG_MISC;
    else if(tag != TAG_MISC)
	g_warning("xml_loadsave_misc_end_element: unknown tag: %s; I'm in state %d\n",
		  element_name, state);
}

void
xml_loadsave_misc_text         (GMarkupParseContext *context,
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
	g_string_printf(country.name, "%s", buf);
    else if(state == TAG_SYMBOL)
	g_string_printf(country.symbol, "%s", buf);
    else if(state == TAG_SID)
	g_string_printf(country.sid, "%s", buf);
    else if(state == TAG_MISC_SEASON)
	season = int_value;
    else if(state == TAG_MISC_WEEK)
	week = int_value;
    else if(state == TAG_MISC_WEEK_ROUND)
	week_round = int_value;
}


/** Read a country xml file. */
void
xml_loadsave_misc_read(const gchar *dirname, const gchar *basename)
{
    gchar file[SMALL];
    GMarkupParser parser = {xml_loadsave_misc_start_element,
			    xml_loadsave_misc_end_element,
			    xml_loadsave_misc_text, NULL, NULL};
    GMarkupParseContext *context;
    gchar *file_contents;
    guint length;
    GError *error = NULL;

    sprintf(file, "%s/%s___misc.xml", dirname, basename);

    context = 
	g_markup_parse_context_new(&parser, 0, NULL, NULL);

    if(!g_file_get_contents(file, &file_contents, &length, &error))
    {
	g_warning("xml_loadsave_misc_read: error reading file %s\n", file);
	misc_print_error(&error, TRUE);
    }

    if(g_markup_parse_context_parse(context, file_contents, length, &error))
    {
	g_markup_parse_context_end_parse(context, NULL);
	g_markup_parse_context_free(context);
	g_free(file_contents);
    }
    else
    {
	g_warning("xml_loadsave_misc_read: error parsing file %s\n", file);
	misc_print_error(&error, TRUE);
    }
}

/** Save the country variable into the file. */
void
xml_loadsave_misc_write(const gchar *prefix)
{
    gchar buf[SMALL];
    FILE *fil = NULL;

    sprintf(buf, "%s___misc.xml", prefix);

    file_my_fopen(buf, "w", &fil, TRUE);

    fprintf(fil, "<_%d>\n", TAG_MISC);

    xml_write_g_string(fil, country.name, TAG_NAME, I0);
    xml_write_g_string(fil, country.symbol, TAG_SYMBOL, I0);
    xml_write_g_string(fil, country.sid, TAG_SID, I0);
    xml_write_int(fil, season, TAG_MISC_SEASON, I0);
    xml_write_int(fil, week, TAG_MISC_WEEK, I0);
    xml_write_int(fil, week_round, TAG_MISC_WEEK_ROUND, I0);

    fprintf(fil, "</_%d>\n", TAG_MISC);
    fclose(fil);
}