/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:05:08 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/14 15:13:16 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	check_for_end(char const *s1, char const *set, int start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	if (j == start)
		return (0);
	while (j > start)
	{
		i = 0;
		while (set[i])
		{
			if (s1[j - 1] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		j--;
	}
	return (j);
}

static char	*norminette(char *trimmed_s)
{
	trimmed_s = (char *) malloc(1);
	if (trimmed_s == NULL)
		return (NULL);
	trimmed_s[0] = '\0';
	return (trimmed_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_trim;
	int		end_trim;
	int		i;
	char	*trimmed_s;

	if (!s1 || !set)
		return (NULL);
	trimmed_s = NULL;
	start_trim = check_for_start(s1, set);
	if (start_trim >= (int)ft_strlen(s1))
		return (norminette(trimmed_s));
	end_trim = check_for_end(s1, set, start_trim);
	i = 0;
	trimmed_s = (char *) malloc(sizeof(char) * end_trim - start_trim + 1);
	if (trimmed_s == NULL)
		return (NULL);
	while (start_trim < end_trim)
		trimmed_s[i++] = s1[start_trim++];
	trimmed_s[i] = '\0';
	return (trimmed_s);
}
