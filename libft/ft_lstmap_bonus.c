/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:23:48 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/27 17:48:23 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	t_list	*p;

	arr = 0;
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear (&arr, del);
			return (arr);
		}
		ft_lstadd_back(&arr, p);
		lst = lst->next;
	}
	return (arr);
}
