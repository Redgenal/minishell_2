/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:35 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:36 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_remove(t_list **env)
{
	t_list	*clear;

	clear = (*env)->next;
	(*env)->next = (*env)->next->next;
	free(clear);
}

int	ft_unset(char *str, t_list **env)
{
	int		i;
	int		flag;
	t_list	*first;

	i = -1;
	flag = 0;
	first = *env;
	while ((*env)->next)
	{
		if ((ft_strncmp((*env)->next->content, str, ft_strlen(str)) == 0)
			&& ((*env)->next->content[ft_strlen(str)] == '='))
		{
			ft_remove(env);
			flag = 1;
		}
		(*env) = (*env)->next;
	}
	if (flag == 0)
		perror("No such variable");
	return (0);
}
