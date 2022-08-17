#include "minishell.h"

int strlenght(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int isAlpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

char *get_env_var(char **environ, char *var) {
    int i = 0;
    while (environ[i] && ft_strncmp(environ[i], var, ft_strlen(var)))
        i++;
    if (!environ[i]) {
        char *path = (char *)malloc(sizeof(char) * 1);
        path[0] = '\0';
        return path;
    } else {
        char **paths = ft_split(environ[i], '=');
        char *path = (char *)malloc(sizeof(char) * ft_strlen(paths[1]));
        i = -1;
        while (paths[1][++i])
            path[i] = paths[1][i];
        path[i] = '\0';
        free(paths[0]);
        free(paths[1]);
        free(paths);
        return path;
    }
}

void generate_string(t_line *l, char *res, int x, int j)
{

}

void generate_string_len(t_line *l, char *res, int j)
{
    char    *new;
    int     len;
    int     i;

    len = ft_strlen(res);
    i = 0;
    while(l->line[i] && l->line[i] != '$')
    {
        i++;
        len++;
    }
    while(l->line[j])
    {
        j++;
        len++;
    }
}

void build_new_expanded_string(t_line *l, int x)
{
    int j;
    char *var;
    char *res;

    j = x + 1;
    while (l->line[j] && (isAlpha(l->line[j]) || isDigit(l->line[j]) || l->line[j] == '_'))
        j++;
    var = ft_substr(l->line, x + 1, j - x - 1);
    res = get_env_var(l->env, var);
    generate_string_len(l, res, x, j);
}

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
        if (l->line[i] == ' ' && inside_double_quotes)
            l->line[i] = -1;
        else if (l->line[i] == '|' && inside_double_quotes)
            l->line[i] = -2;
        if (l->line[i] == '$' && inside_double_quotes)
        {
            // build a new string with the contents of the variable
            build_new_expanded_string(l, i);
        }
        i++;
    }
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
