/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:35:24 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/13 10:45:30 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				s;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s *= -1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (res * s);
		res = (res * 10) + str[i++] - '0';
		if (res > 9223372036854775807)
		{
			if (s < 0)
				return (0);
			return (-1);
		}
	}
	return (res * s);
}
