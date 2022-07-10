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

void	ft_remove(char **env, int n)
{
	while (env[n])
	{
		env[n] = env[n + 1];
		n++;
	}
}

int ft_unset(char *str, char **env)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (env[++i])
	{
		if (strncmp(env[i], str, ft_strlen(str)) == 0 && env[i][ft_strlen(str)] == '=')
		{
			ft_remove(env, i);
			flag = 1;
		}
	}
	if (flag == 0)
		perror("No such variable");
	return (0);
}
