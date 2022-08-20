#include "minishell.h"

char *get_env_var(char **environ, char *var) {
    int     i;
    char    *path;

    i = 0;
    while (environ[i] && ft_strncmp(environ[i], var, ft_strlen(var)))
        i++;
    if (!environ[i]) {
        path = (char *)malloc(sizeof(char) * 1);
        path[0] = '\0';
    } else {
        char **paths = ft_split(environ[i], '=');
        path = ft_strdup(paths[1]);
        free(paths[0]);
        free(paths[1]);
        free(paths);
    }
    return path;
}

void generate_string(t_line *l, int len, int x, int j)
{
    int i;
    int k;
    char *new;

    i = 0;
    new = (char *)malloc(sizeof(char) * (len + 1));
    while (i < x)
    {
        new[i] = l->temp[i];
        i++;
    }
    k = 0;
    while (l->expanded_var[k])
        new[i++] = l->expanded_var[k++];
    while (l->temp[j])
        new[i++] = l->temp[j++];
    new[i] = '\0';
    free(l->temp);
    l->temp = new;
}

int generate_string_len(t_line *l, int j)
{
    int     len;
    int     i;

    len = ft_strlen(l->expanded_var);
    i = 0;
    while(l->temp[i] && l->temp[i] != '$')
    {
        i++;
        len++;
    }
    while(l->temp[j])
    {
        j++;
        len++;
    }
    return (len);
}

void build_new_expanded_string(t_line *l, int x)
{
    int j;
    int len;
    char *var;

    j = x + 1;
    while (l->temp[j] && (ft_isalpha(l->temp[j]) || ft_isdigit(l->temp[j]) || l->temp[j] == '_'))
        j++;
    var = ft_substr(l->temp, x + 1, j - x - 1);
    l->expanded_var = get_env_var(l->env, var);
    free(var);
    len = generate_string_len(l, j);
    generate_string(l, len, x, j);
}

void expand(t_line *l)
{
    int i;
    int inside_double_quotes;
    int inside_single_quotes;

    i = 0;
    inside_double_quotes = 0;
    inside_single_quotes = 0;
    while (l->temp[i])
    {
        if (l->temp[i] == '"' && !inside_single_quotes)
            inside_double_quotes = !inside_double_quotes;
        else if (l->temp[i] == '\'' && !inside_double_quotes)
            inside_single_quotes = !inside_single_quotes;
        if (l->temp[i] == '$' && (inside_double_quotes || (!inside_single_quotes && !inside_double_quotes)))
            build_new_expanded_string(l, i);
        i++;
    }
}
