/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_in_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:05:29 by utawana           #+#    #+#             */
/*   Updated: 2022/08/20 14:49:37 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_call_file_not_found(t_main *m_s, char *str)
{
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	m_s->status = 127;
	return (-127);
}

int	ft_is_a_dire(t_main *m_s, char *str)
{
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": is a directory\n", 2);
	m_s->status = 126;
	return (-126);
}

int	ft_perm_denied(t_main *m_s, char *str)
{
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	m_s->status = 1;
	return (-1);
}

int	ft_call_file_not_open(t_main *m_s, char *str)
{
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	m_s->status = 1;
	return (-1);
}
