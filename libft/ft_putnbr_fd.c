/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:08:06 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/10 08:51:59 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
	{
		un = -n;
		ft_putchar_fd('-', fd);
	}
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}
