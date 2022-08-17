/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerraqui <yerraqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:14:57 by yerraqui          #+#    #+#             */
/*   Updated: 2021/11/14 15:35:36 by yerraqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	temp2 = *lst;
	if (lst && *lst && del)
	{
		while (temp != NULL)
		{
			del(temp->content);
			temp = temp->next;
			free(temp2);
			temp2 = temp;
		}
	}
	*lst = NULL;
}
