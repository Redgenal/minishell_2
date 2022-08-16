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

#include "../headers/minishell.h"

void	ft_remove(t_list **env, int *flag)
{
	t_list	*clear;

	clear = (*env)->next;
	(*env)->next = clear->next;
	free(clear);
	*flag = 1;
}

int	ft_unset(char *str, t_list **env)
{
	int		flag;
	t_list	*first;

	flag = 0;
	first = *env;
	while ((*env)->next != NULL)
	{
		if ((ft_strncmp((*env)->next->content, str, ft_strlen(str)) == 0)
			&& ((*env)->next->content[ft_strlen(str)] == '='))
			ft_remove(env, &flag);
		if ((*env)->next)
			(*env) = (*env)->next;
	}
	*env = first;
	if (flag == 0)
		perror("No such variable");
	return (0);
}
