/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:28:50 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/27 17:48:01 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*tmp;

	p = *lst;
	if (lst)
	{
		if (p)
		{
			while (p)
			{
				tmp = p->next;
				if (del)
					del (p->content);
				free(p);
				p = tmp;
			}
			*lst = 0;
		}
	}
}
