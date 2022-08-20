/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:37:57 by utawana           #+#    #+#             */
/*   Updated: 2022/08/19 20:38:15 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_help_export(char **split, t_list **env, char *str, t_list *first)
{
	if (ft_strncmp_ust(str, (*env)->content,
			ft_strlen(split[0])) == 777)
	{
		*env = first;
		ft_unset(split[0], env);
	}
}
