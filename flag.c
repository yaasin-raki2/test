#include "minishell.h"

static void heeelp(t_line *l, int *idq, int *isq, int i)
{
    if (l->line[i] == '"' && !(*isq))
        *idq = !(*idq);
    else if (l->line[i] == '\'' && !(*idq))
        *isq = !(*isq);
    if (l->line[i] == ' ' && (!(*idq) || *isq))
        l->line[i] = -1;
    else if (l->line[i] == '|' && (*idq || *isq))
        l->line[i] = -2;
    if (l->line[i] == '"' && *isq)
        l->line[i] = -3;
    if (l->line[i] == '\'' && *idq)
        l->line[i] = -4;
}

void flag_in_quotes(t_line *l)
{
    int i;
    int idq;
    int isq;

    i = 0;
    idq = 0;
    isq = 0;
    while (l->line[i])
    {
        heeelp(l, &idq, &isq, i);
        i++;
    }
    if (idq || isq)
        printf("Error: Unmatched quotes\n");
}

void deflag_in_quotes(char *str)
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
