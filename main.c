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
        if (l->line[i] == '$' && (inside_double_quotes || (!inside_single_quotes && !inside_double_quotes)))
            build_new_expanded_string(l, i);
        i++;
    }
    if (inside_double_quotes || inside_single_quotes)
        printf("Error: Unmatched quotes\n");
}

int main(int ac, char **av, char **env)
{
    t_line *l;

    l = (t_line *)malloc(sizeof(t_line));
    l->env = env;
    while (1)
    {
        l->line = readline("$>");
        flag_in_quotes(l);
        printf("%s\n",l->line);
    }
    return (0);
}
