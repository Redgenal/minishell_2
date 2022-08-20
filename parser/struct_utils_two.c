/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:45:49 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/04 20:22:53 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*get_list_redir(char **envp)
{
	t_redir	*env;
	t_redir	*list;
	int		i;

	i = -1;
	env = NULL;
	while (envp[++i] != NULL)
	{
		if (get_redir(envp[i]) != -1)
		{
			list = ft_redirnew(envp[i], envp[i + 1]);
			ft_rediradd_back(&env, list);
		}
	}
	if (env)
	{
		list = NULL;
		ft_rediradd_back(&env, list);
	}
	return (env);
}
