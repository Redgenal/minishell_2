/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:51:22 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/27 17:47:42 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_lstlast(*(lst));
			p->next = new;
		}
		else
			*lst = new;
	}
}
