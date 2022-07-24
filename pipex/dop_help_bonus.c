/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_help_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:51:01 by utawana           #+#    #+#             */
/*   Updated: 2022/02/09 17:54:22 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**ft_create_pipes(int argc)
{
	int	**pipes;
	int	i;

	i = -1;
	pipes = (int **)malloc(sizeof(int *) * (argc - 1));
	if (!pipes)
		return (NULL);
	while (++i < (argc - 1))
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
			return (NULL);
	}
	return (pipes);
}

void	ft_free_all(int **pipes, int argc)
{
	int	i;

	i = -1;
	while (++i < (argc - 4))
		free(pipes[i]);
	free(pipes);
}

void	ft_close_all(int **pipes, int argc)
{
	int	i;

	i = -1;
	while (++i < (argc - 4))
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
}

// int	ft_choose_child(int **pipes, char **argv, char **envp, int i)
// {
// 	if ((ft_strncmp(argv[1], "here_doc", 8) == 0))
// 	{
// 		if (i == 0)
// 		{
// 			ft_for_first_hand_child(pipes, argv, envp, 3);
// 			return (1);
// 		}
// 		else
// 			ft_for_circle_hand_child(pipes, argv, envp, i);
// 	}
// 	else
// 	{
// 		if (i == 0)
// 			ft_for_first_child(pipes, argv, envp, 2);
// 		else
// 			ft_for_circle_child(pipes, argv, envp, i);
// 	}
// 	return (0);
// }

// void	ft_choose_last_child(int **pipes, char **argv, char **envp, int i)
// {
// 	if ((ft_strncmp(argv[1], "here_doc", 8) == 0))
// 		ft_for_last_hand_child(pipes, argv, envp, i);
// 	else
// 		ft_for_last_child(pipes, argv, envp, i);
// }
