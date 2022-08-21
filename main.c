#include "minishell.h"

void    parse_quotes(t_line *l)
{
    flag_in_quotes(l);
    l->temp = ft_strdup(l->line);
    expand(l);
    remove_quotes(l, '"');
    remove_quotes(l, '\'');
    free(l->line);
    l->line = ft_strdup(l->temp);
    free(l->temp);
    deflag_in_quotes(l->line);
}

int main(int ac, char **av, char **env)
{
    t_line *l;

    l = (t_line *)malloc(sizeof(t_line));
    l->env = env;
    while (1)
    {
        l->line = readline("$>");
        parse_quotes(l);
        printf("%s\n",l->line);
//        system("leaks minishell");
    }
    return (0);
}
