/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:18:35 by utawana           #+#    #+#             */
/*   Updated: 2022/08/04 18:48:39 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_do_ur_job(t_main *m_s, t_list **env, char **my_env)
{
	if (ft_for_buildins(m_s->p_list->args[0], env, m_s->p_list->args) == 666)
		return (ft_obrabotka(m_s->p_list->args, my_env));
	return (m_s->status);
}