/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:08:42 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/14 15:50:17 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p;
	char	*p2;

	p = (char *)dst;
	p2 = (char *)src;
	i = 0;
	if (!p && !p2)
		return (NULL);
	if (p2 < p)
		while (++i <= len)
		p[len - i] = p2[len - i];
	else
		while (len-- > 0)
		*(p++) = *(p2++);
	return (dst);
}
