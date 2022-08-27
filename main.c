#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_line *l;

    l = (t_line *)malloc(sizeof(t_line));
    l->env = env;
    while (1)
    {
        l->line = readline("$>");
        flag_in_quotes(l);
        l->temp = ft_strdup(l->line);
        expand_it(l);
        remove_quotes(l, '"');
        remove_quotes(l, '\'');
        deflag_in_quotes(l->temp);
        printf("%s\n", l->temp);
        free(l->line);
        free(l->temp);
    }
    return (0);
}
