#include "minishell.h"

void remove_one(t_line *l, int x)
{
	char *new;
	int i;
	int j;

	new = (char *)malloc(sizeof(char) * (ft_strlen(l->temp) - 1 + 1));
	i = 0;
	j = 0;
	while (l->temp[j])
	{
		if (i == x)
			j++;
		new[i] = l->temp[j];
		j++;
		i++;
	}
	new[i] = '\0';
	free(l->temp);
	l->temp = new;
}

// compare strings until equal sign
int compare_strings(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '=' && !s2[i])
		return (1);
	return (0);
}

char *get_env(char **environ, char *var)
{
	int i;
	char *path;

	i = 0;
	while (environ[i] && !compare_strings(environ[i], var))
		i++;
	if (!environ[i] || var[0] == '\0')
	{
		path = (char *)malloc(sizeof(char) * 1);
		path[0] = '\0';
	}
	else
	{
		char **paths = ft_split(environ[i], '=');
		path = ft_strdup(paths[1]);
		free(paths[0]);
		free(paths[1]);
		free(paths);
	}
	return path;
}

void again(t_line *l, char *ex, int x, int len)
{
	int i;
	int j;
	char *new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(l->temp) - len + ft_strlen(ex) + 1));
	while (i < x)
	{
		new[i] = l->temp[i];
		i++;
	}
	j = 0;
	while (ex[j])
		new[i++] = ex[j++];
	while (l->temp[x + len])
		new[i++] = l->temp[x++ + len];
	new[i] = '\0';
	free(l->temp);
	l->temp = new;
}

void build_it(t_line *l, int x)
{
	int i;
	char *var;
	char *ex;

	i = x;
	while (l->temp[i])
	{
		if (!ft_isalnum(l->temp[i]) && l->temp[i] != '_')
			break;
		i++;
	}
	var = ft_substr(l->temp, x, i - x);
	ex = get_env(l->env, var);
	free(var);
	//printf("ex: |%s|\tlen: |%zu|\n", ex, ft_strlen(ex));
	again(l, ex, x, i - x);
}

void expand_it(t_line *l)
{
	int i;
	int inside;

	i = 0;
	inside = 0;
	while (l->temp[i])
	{
		if (l->temp[i] == '"' && inside == 0)
			inside = 2;
		else if (l->temp[i] == '\'' && inside == 0)
			inside = 1;
		else if (l->temp[i] == '"' && inside == 2)
			inside = 0;
		else if (l->temp[i] == '\'' && inside == 1)
			inside = 0;
		if (l->temp[i] == '$' && inside == 2)
		{
			if (l->temp[i + 1] != '"' && l->temp[i + 1] != -3 && l->temp[i + 1] != -4 && !ft_isalnum(l->temp[i + 1]) && l->temp[i + 1] != '_')
			{
				remove_one(l, i);
				continue;
			}
			if (ft_isalnum(l->temp[i + 1]) || l->temp[i + 1] == '_')
			{
				remove_one(l, i);
				build_it(l, i);
				continue;
			}
		}
		else if (l->temp[i] == '$' && inside == 0)
		{
			if (l->temp[i + 1] == '"' || l->temp[i + 1] == '\'')
			{
				remove_one(l, i);
				continue;
			}
			else if (ft_isalnum(l->temp[i + 1]) || l->temp[i + 1] == '_')
			{
				remove_one(l, i);
				build_it(l, i);
				continue;
			}
		}
		i++;
	}
}
