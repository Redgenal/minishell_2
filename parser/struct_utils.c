/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:42:50 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/03 19:50:21 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lis	*ft_lislast(t_lis *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lisadd_back(t_lis **lst, t_lis *new)
{
	t_lis	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_lislast(*(lst));
			p->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_rediradd_back(t_redir **lst, t_redir *new)
{
	t_redir	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_redirlast(*(lst));
			p->next = new;
		}
		else
			*lst = new;
	}
}

t_redir	*ft_redirnew(void *type, void *content)
{
	t_redir	*p;

	p = (t_redir *) malloc(sizeof(*p));
	if (!p)
		return (0);
	p->file = content;
	p->type = get_redir(type);
	p->next = NULL;
	return (p);
}

t_redir	*ft_redirlast(t_redir *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}
