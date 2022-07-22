/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_with_hands_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:34 by utawana           #+#    #+#             */
/*   Updated: 2022/02/11 16:18:36 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_here_doc(char *stop)
{
	int		pip[2];
	char	*buff;

	buff = malloc(sizeof(*buff));
	pipe(pip);
	while (buff != NULL)
	{
		free(buff);
		write(1, "> ", 1);
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

void	ft_for_first_hand_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		fd1;
	int		d1;
	int		d2;

	fd1 = ft_here_doc(argv[2], argv);
	if (fd1 == -1)
		ft_call_cant_open();
	d1 = dup2(fd1, 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(pipe[0][1], 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[0][0]);
	cmd = ft_delenie_cmd(argv[i]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}

void	ft_for_circle_hand_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		d1;
	int		d2;

	d1 = dup2(pipe[i - 1][0], 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(pipe[i][1], 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[i - 1][0]);
	close(pipe[i - 1][1]);
	close(pipe[i][0]);
	cmd = ft_delenie_cmd(argv[i + 2]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}

void	ft_for_last_hand_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		fd2;
	int		d1;
	int		d2;

	fd2 = open(argv[i + 3], O_CREAT | O_APPEND | O_RDWR, 0777);
	if (fd2 == -1)
		ft_call_exit();
	d1 = dup2(pipe[i - 1][0], 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(fd2, 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[i - 1][0]);
	close(pipe[i - 1][1]);
	cmd = ft_delenie_cmd(argv[i + 2]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}
