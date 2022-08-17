/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:33:49 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/10 14:29:04 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int x, int e)
{
	int	res;

	res = 1;
	while (e-- > 0)
		res *= x;
	return (res);
}

static char	*handle_zero(void)
{
	char	*ascii;

	ascii = (char *)malloc(sizeof(char) * 2);
	ascii[0] = '0';
	ascii[1] = 0;
	return (ascii);
}

static void	negative(unsigned int *un, int *s, int n)
{
	*un = -n;
	*s = 1;
}

void	norminette(char *ascii, int e, unsigned int un, unsigned int x)
{
	while (e >= 0)
		ascii[x++] = ((un / ft_pow(10, e--)) % 10) + '0';
	ascii[x] = '\0';
}

char	*ft_itoa(int n)
{
	char			*ascii;
	unsigned int	un;
	unsigned int	x;
	int				e;
	int				s;

	e = -1;
	s = 0;
	if (n == 0)
		return (handle_zero());
	else if (n < 0)
		negative(&un, &s, n);
	else
		un = n;
	x = un;
	while (x && (++e + 1))
		x /= 10;
	ascii = (char *)malloc(sizeof(char) * (e + 1 + s + 1));
	if (!ascii)
		return (NULL);
	x = 0;
	if (s)
		ascii[x++] = '-';
	norminette(ascii, e, un, x);
	return (ascii);
}
