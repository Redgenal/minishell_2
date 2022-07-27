/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:52:50 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/27 17:48:09 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	size_t	i;

	i = 0;
	if (!f || !lst)
		return ;
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
