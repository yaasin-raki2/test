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
        new[i] = l->line[i];
        i++;
    }
    k = 0;
    while (l->expanded_var[k])
        new[i++] = l->expanded_var[k++];
    while (l->line[j])
        new[i++] = l->line[j++];
    new[i] = '\0';
    free(l->line);
    l->line = new;
}

int generate_string_len(t_line *l, int j)
{
    int     len;
    int     i;

    len = ft_strlen(l->expanded_var);
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
    return (len);
}

void build_new_expanded_string(t_line *l, int x)
{
    int j;
    int len;
    char *var;

    j = x + 1;
    while (l->line[j] && (ft_isalpha(l->line[j]) || ft_isdigit(l->line[j]) || l->line[j] == '_'))
        j++;
    var = ft_substr(l->line, x + 1, j - x - 1);
    l->expanded_var = get_env_var(l->env, var);
    len = generate_string_len(l, j);
    generate_string(l, len, x, j);
    free(l->expanded_var);
}
