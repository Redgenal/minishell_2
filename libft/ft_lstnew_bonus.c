/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:48:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/27 17:48:17 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *) malloc(sizeof(*p));
	if (!p)
		return (0);
	p -> content = content;
	p -> next = 0;
	return (p);
}
