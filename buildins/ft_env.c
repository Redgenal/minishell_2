/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:00 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:02 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_env(t_list *env)
{
	t_list	*first;

	first = env;
	while (env != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	env = first;
	return (0);
}
