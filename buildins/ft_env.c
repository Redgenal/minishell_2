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

#include "../minishell.h"

int	ft_env(t_list *env)
{
	int	i;

	i = -1;
	while (env->next != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	return (0);
}
