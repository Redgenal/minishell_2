/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:48:35 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/19 14:53:57 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *) malloc(sizeof(*p));
	if (!p)
		return (0);
	p->content = malloc(sizeof(char) * (ft_strlen(content) + 1));
	ft_memcpy(p->content, content, ft_strlen(content) + 1);
	p -> next = NULL;
	return (p);
}
