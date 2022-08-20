#include "minishell.h"

void remove_quotes(t_line *l, char quote_type)
{
    int i;
    int j;
    int n;
    char *new;

    i = 0;
    n = 0;
    while (l->temp[i])
    {
        if (l->temp[i] == quote_type)
            n++;
        i++;
    }
    new = (char *)malloc(sizeof(char) * (ft_strlen(l->temp) - n + 1));
    i = 0;
    j = 0;
    while (l->temp[i])
    {
        if (l->temp[i] == quote_type)
            i++;
        else
            new[j++] = l->temp[i++];
    }
    new[j] = '\0';
    free(l->temp);
    l->temp = new;
}