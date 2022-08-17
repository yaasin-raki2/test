/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:10:12 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/14 17:45:09 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	i = 0;
	if (dlen + 1 < dstsize && dstsize > 0)
	{
		while (src[i] && dlen + i + 1 < dstsize)
			dst[j++] = src[i++];
		dst[j] = 0;
	}
	if (dlen >= dstsize)
		return (dstsize + slen);
	return (dlen + slen);
}
