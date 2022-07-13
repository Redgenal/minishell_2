/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_with_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:04:47 by utawana           #+#    #+#             */
/*   Updated: 2022/02/04 16:04:49 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_find_path(char **envp)
{
	char	**arr;
	int		i;

	i = 0;
	while (envp[i++] != NULL)
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	arr = ft_split(envp[i] + 5, ':');
	if (arr == NULL)
		ft_call_exit("Error");
	return (arr);
}

char	**ft_delenie_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}

char	**ft_check_file(char **arr, char **cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arr[i++] != NULL)
	{
		tmp = ft_strjoin(ft_strjoin(arr[i], "/"), cmd[0]);
		if (tmp == NULL)
			ft_call_com_not_found(cmd[0]);
		if (access(tmp, 0))
			free(tmp);
		else
		{
			free(cmd[0]);
			cmd[0] = tmp;
			return (cmd);
		}
	}
	return (NULL);
}

char	**ft_first_check_file(char **cmd)
{
	if (access(cmd[0], 0) == 0)
		return (cmd);
	else
		return (NULL);
}

char	**ft_change_cmd(char **cmd, char **envp)
{
	char	**path;
	char	**cmd1;
	char	**cmd2;

	if (cmd[0] == NULL)
		ft_call_com_not_found(cmd[0]);
	path = ft_find_path(envp);
	cmd1 = ft_first_check_file(cmd);
	if (cmd1 != NULL)
		return (cmd1);
	cmd2 = ft_check_file(path, cmd);
	if (cmd2 == NULL)
		ft_call_com_not_found(cmd[0]);
	return (cmd2);
}
