#include "minishell.h"

static void first_if(t_line *l, int *i)
{
	if (l->temp[*i + 1] != '"' && l->temp[*i + 1] != -3 && l->temp[*i + 1] != -4 && !ft_isalnum(l->temp[*i + 1]) && l->temp[*i + 1] != '_')
		remove_one(l, *i);
	else if (ft_isalnum(l->temp[*i + 1]) || l->temp[*i + 1] == '_')
	{
		remove_one(l, *i);
		build_it(l, *i);
	}
	else
		*i += 1;
}

static void second_if(t_line *l, int *i)
{
	if (l->temp[*i + 1] == '"' || l->temp[*i + 1] == '\'')
		remove_one(l, *i);
	else if (ft_isalnum(l->temp[*i + 1]) || l->temp[*i + 1] == '_')
	{
		remove_one(l, *i);
		build_it(l, *i);
	}
	else
		*i += 1;
}

void expand_it(t_line *l)
{
	int i;
	int in;

	i = 0;
	in = 0;
	while (l->temp[i])
	{
		if (l->temp[i] == '"' && in == 0)
			in = 2;
		else if (l->temp[i] == '\'' && in == 0)
			in = 1;
		else if ((l->temp[i] == '"' && in == 2)
			|| (l->temp[i] == '\'' && in == 1))
			in = 0;
		if (l->temp[i] == '$' && in == 2)
			first_if(l, &i);
		else if (l->temp[i] == '$' && in == 0)
			second_if(l, &i);
		else
			i++;
	}
}
