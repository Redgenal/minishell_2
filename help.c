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

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
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

int	ft_here_doc(char *stop)
{
	int		pip[2];
	char	*buff;

	buff = malloc(sizeof(*buff));
	pipe(pip);
	while (buff != NULL)
	{
		free(buff);
		write(1, "> ", 2);
		buff = get_next_line(0);
		if (ft_strncmp(buff, stop, ft_strlen(stop) + 1) == 0)
			break ;
		write(pip[1], buff, ft_strlen(buff));
		write(pip[1], "\n", 1);
	}
	if (buff)
		free(buff);
	close(pip[1]);
	return (pip[0]);
}

int	ft_liss_len(t_lis *env)
{
	int	i;

	i = 1;
	while (env->next)
	{
		i++;
		env = env->next;
	}
	return (i);
}
