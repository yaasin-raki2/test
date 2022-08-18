#include "minishell.h"

void remove_quotes(char *str, char quote_type)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == quote_type)
            str[i] = ' ';
        i++;
    }
}