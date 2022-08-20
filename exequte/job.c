/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:18:35 by utawana           #+#    #+#             */
/*   Updated: 2022/08/20 14:45:37 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_do_ur_job(t_main *m_s, t_list **env, char **my_env)
{
	int	rez;

	rez = 0;
	sig_func();
	rez = ft_for_buildins(m_s->p_list->args[0], env, m_s->p_list->args);
	if (rez == 666)
		return (ft_obrabotka(m_s->p_list->args, my_env));
	return (rez);
}

int	ft_for_buildins(char *com, t_list **env, char **arg)
{
	if (ft_strncmp(com, "cd", 3) == 0)
		return (ft_cd(arg[1], env));
	else if (ft_strncmp(com, "env", 4) == 0)
		return (ft_env(*env));
	else if (ft_strncmp(com, "export", 7) == 0)
		return (ft_export(env, arg));
	else if (ft_strncmp(com, "echo", 5) == 0)
		return (ft_echo(arg));
	else if (ft_strncmp(com, "exit", 5) == 0)
		return (ft_exit(arg[1], arg));
	else if (ft_strncmp(com, "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(com, "unset", 6) == 0)
		return (ft_unset(arg[1], env));
	else
		return (666);
}

int	ft_lists_len(t_list *env)
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

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_p_list_clear(t_lis *p_list)
{
	t_lis	*tmp;
	int		i;
	t_redir	*red;

	while (p_list)
	{
		i = ft_arr_len(p_list->args);
		tmp = p_list->next;
		while (--i >= 0)
		{
			free(p_list->args[i]);
			p_list->args[i] = NULL;
		}
		free(p_list->args);
		while (p_list->redir)
		{
			red = p_list->redir->next;
			free (p_list->redir);
			p_list->redir = red;
		}
		free(p_list);
		p_list = tmp;
	}
}
