#include "minishell.h"

void    flag_in_quotes(t_line *l)
{
    int i;
    int inside_double_quotes;
    int inside_single_quotes;

    i = 0;
    inside_double_quotes = 0;
    inside_single_quotes = 0;
    while (l->line[i])
    {
        if (l->line[i] == '"' && !inside_single_quotes)
            inside_double_quotes = !inside_double_quotes;
        else if (l->line[i] == '\'' && !inside_double_quotes)
            inside_single_quotes = !inside_single_quotes;
        if (l->line[i] == ' ' && (inside_double_quotes || inside_single_quotes))
            l->line[i] = -1;
        else if (l->line[i] == '|' && (inside_double_quotes || inside_single_quotes))
            l->line[i] = -2;
        if (l->line[i] == '"' && inside_single_quotes)
            l->line[i] = -3;
        if (l->line[i] == '\'' && inside_double_quotes)
            l->line[i] = -4;
        i++;
    }
    if (inside_double_quotes || inside_single_quotes)
        printf("Error: Unmatched quotes\n");
}

void    deflag_in_quotes(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == -1)
            str[i] = ' ';
        else if (str[i] == -2)
            str[i] = '|';
        else if (str[i] == -3)
            str[i] = '"';
        if (str[i] == -4)
            str[i] = '\'';
        i++;
    }
}
