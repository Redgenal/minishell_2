/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:23:48 by utawana           #+#    #+#             */
/*   Updated: 2022/08/20 14:59:39 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lets_dup(t_main *m_s, int fd)
{
	int	d1;

	if (m_s->p_list->redir->type == 1 || m_s->p_list->redir->type == 3)
	{
		d1 = dup2(fd, STDIN_FILENO);
		if (d1 == -1)
			return (ft_call_file_not_found(m_s, m_s->p_list->redir->file));
		close(fd);
	}
	else
	{
		d1 = dup2(fd, STDOUT_FILENO);
		if (d1 == -1)
			return (ft_call_file_not_found(m_s, m_s->p_list->redir->file));
		close(fd);
	}
	return (d1);
}

int	ft_get_in_fd(t_main *m_s, t_lis *p_list)
{
	int	fd;

	if (opendir(p_list->redir->file))
		return (ft_is_a_dire(m_s, p_list->redir->file));
	if (p_list->redir->type == 1)
	{
		fd = open(p_list->redir->file, O_RDWR, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(m_s, p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(m_s, p_list->redir->file));
	}
	else
		fd = ft_here_doc(p_list->redir->file);
	return (fd);
}

int	ft_get_out_fd(t_main *m_s, t_lis *p_list)
{
	int	fd;

	if (opendir(p_list->redir->file))
		return (ft_is_a_dire(m_s, p_list->redir->file));
	if (p_list->redir->type == 0)
	{
		fd = open(p_list->redir->file, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(m_s, p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(m_s, p_list->redir->file));
	}
	else
	{
		fd = open(p_list->redir->file, O_CREAT | O_APPEND | O_RDWR, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(m_s, p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(m_s, p_list->redir->file));
	}
	return (fd);
}

int	ft_dup_call(t_main *m_s, t_list **env, char **my_env)
{
	int		fd;
	int		d1;
	t_redir	*first;

	first = m_s->p_list->redir;
	while (m_s->p_list->redir != NULL)
	{
		if (access(m_s->p_list->redir->file, R_OK | W_OK)
			&& m_s->p_list->redir->type == 1)
			return (ft_call_file_not_open(m_s, m_s->p_list->redir->file));
		if (m_s->p_list->redir->type == 0 || m_s->p_list->redir->type == 4)
			fd = ft_get_out_fd(m_s, m_s->p_list);
		if (m_s->p_list->redir->type == 1 || m_s->p_list->redir->type == 3)
			fd = ft_get_in_fd(m_s, m_s->p_list);
		if (fd < 0)
			return (fd);
		d1 = ft_lets_dup(m_s, fd);
		if (d1 == -127)
			return (d1);
		m_s->p_list->redir = m_s->p_list->redir->next;
	}
	m_s->p_list->redir = first;
	return (ft_do_ur_job(m_s, env, my_env));
}
