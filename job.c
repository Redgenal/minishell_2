/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:18:35 by utawana           #+#    #+#             */
/*   Updated: 2022/07/24 18:18:37 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_do_ur_job(t_lis *p_list, t_list **env, char **my_env)
{
	int	status;

	if (ft_for_buildins(p_list->args[0], env, p_list->args) == 666)
		ft_obrabotka(p_list->args, my_env);
	return (WEXITSTATUS(status));
}

