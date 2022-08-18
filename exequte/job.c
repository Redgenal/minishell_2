/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:18:35 by utawana           #+#    #+#             */
/*   Updated: 2022/08/18 19:39:37 by utawana          ###   ########.fr       */
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
