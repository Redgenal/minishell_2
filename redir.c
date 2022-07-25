/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:23:48 by utawana           #+#    #+#             */
/*   Updated: 2022/07/22 20:23:50 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lets_dup(t_lis *p_list, int fd)
{
	int	d1;

	if (p_list->redir->type == 0 || p_list->redir->type == 3)
	{
		d1 = dup2(fd, STDIN_FILENO);
		if (d1 == -1)
			return (ft_call_file_not_found(p_list->redir->file));
		close(fd);
	}
	else
	{
		d1 = dup2(fd, STDOUT_FILENO);
		if (d1 == -1)
			return (ft_call_file_not_found(p_list->redir->file));
		close(fd);
	}
	return (d1);
}

int	ft_get_in_fd(t_lis *p_list)
{
	int	fd;

	if (opendir(p_list->redir->file))
		return (ft_is_a_dire(p_list->redir->file));
	if (p_list->redir->type == 0)
	{
		fd = open(p_list->redir->file, O_RDWR, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(p_list->redir->file));
	}
	else
		fd = ft_here_doc(p_list->redir->file);
	return (fd);
}

int	ft_get_out_fd(t_lis *p_list)
{
	int	fd;

	if (opendir(p_list->redir->file))
		return (ft_is_a_dire(p_list->redir->file));
	if (p_list->redir->type == 1)
	{
		fd = open(p_list->redir->file, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(p_list->redir->file));
	}
	else
	{
		fd = open(p_list->redir->file, O_CREAT | O_APPEND | O_RDWR, 0777);
		if (access(p_list->redir->file, R_OK | W_OK))
			return (ft_perm_denied(p_list->redir->file));
		if (fd == -1)
			return (ft_call_file_not_found(p_list->redir->file));
	}
	return (fd);
}

int	ft_dup_call(t_lis *p_list, t_list **env, char **my_env)
{
	int	fd;
	int	d1;

	while (p_list->redir != NULL)
	{
		if (access(p_list->redir->file, R_OK | W_OK)
			&& p_list->redir->type == 0)
		{
			ft_call_file_not_found(p_list->redir->file);
			return (1);
		}
		if (p_list->redir->type == 1 || p_list->redir->type == 4)
			fd = ft_get_out_fd(p_list);
		if (p_list->redir->type == 0 || p_list->redir->type == 3)
			fd = ft_get_in_fd(p_list);
		if (fd < 0)
			return (fd * -1);
		d1 = ft_lets_dup(p_list, fd);
		p_list->redir = p_list->redir->next;
	}
	return (ft_do_ur_job(p_list, env, my_env));
}
