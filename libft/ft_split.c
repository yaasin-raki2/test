/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:17:42 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/15 07:32:41 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s1, char c)
{
	int	words;
	int	inside;

	words = 0;
	inside = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			inside = 0;
		else if (inside == 0)
		{
			inside = 1;
			words++;
		}
		s1++;
	}
	return (words);
}

static int	word_len(char const *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**delete(char **res, int j)
{
	while (j-- > 0)
		free((void *)res[j]);
	free(res);
	return (NULL);
}

static char	**allocate_words(char const *s, char **res, char c, int words_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * word_len(s, c, i) + 1);
		if (res[j] == NULL)
			return (delete(res, j));
		while (s[i] != '\0' && s[i] != c)
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	return (allocate_words(s, res, c, words));
}
