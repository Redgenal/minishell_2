/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:08:41 by utawana           #+#    #+#             */
/*   Updated: 2022/07/11 16:08:43 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lists_len(t_list *env)
{
	int	i;

	i = 0;
	while (env->next)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**ft_from_lists_to_str(t_list *env)
{
	char	**envp;
	int		i;
	int		j;

	i = ft_lists_len(env);
	envp = malloc(sizeof(char *) * (i + 1));
	j = -1;
	while (++j < i)
	{
		envp[j] = malloc(sizeof(char) * (ft_strlen(env->content) + 1));
		envp[j] = ft_memcpy(envp[j], env->content, ft_strlen(env->content) + 1);
		if (env->next)
			env = env->next;
	}
	envp[j] = NULL;
	return (envp);
}
