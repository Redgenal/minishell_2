/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:16 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:18 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_no_arg(char **env)
{
	int		i;
	char	**parse;

	i = -1;
	while (env[++i])
	{
		if (env[i])
		{
			parse = ft_split(env[i], '=');
			printf("declare -x %s=%c%s%c\n", parse[0], '"', parse[1], '"');
		}
	}
	return (0);
}

int	ft_export(char **env, char *str)
{
	int	i;

	i = -1;
	if (!str)
		ft_no_arg(env);
	else
	{
		i++;
		while (env[i])
			i++;
		env[i] = str;
		env[++i] = NULL;
	}
	return (0);
}
