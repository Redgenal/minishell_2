/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfile_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:46:42 by utawana           #+#    #+#             */
/*   Updated: 2022/08/20 14:43:58 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*ft_create_env(char **envp)
{
	t_list	*env;
	t_list	*list;
	int		i;

	i = -1;
	env = NULL;
	while (envp[++i] != NULL)
	{
		list = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, list);
	}
	return (env);
}

void	ft_circle_pipes_redir(int **pipes, int i)
{
	int	d1;
	int	d2;

	d1 = dup2(pipes[i - 1][0], 0);
	if (d1 == -1)
		ft_call_exit("dup error");
	close(pipes[i - 1][0]);
	d2 = dup2(pipes[i][1], 1);
	if (d2 == -1)
		ft_call_exit("dup error");
	close(pipes[i][1]);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (--i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	if (arr != NULL)
		free(arr);
}

int	ft_create_main_pipes(int ***pipes, t_lis *p_list)
{
	if (p_list->next != NULL)
	{
		(*pipes) = ft_create_pipes(ft_liss_len(p_list));
		if (!(*pipes))
			return (-1);
	}
	return (0);
}

int	ft_error_return(pid_t pid, t_main *main_struct, int **pipes, t_list **env)
{
	t_list	*tmp;

	dup2(main_struct->in, 0);
	dup2(main_struct->out, 1);
	while (*env)
	{
		tmp = (*env)->next;
		free((*env)->content);
		free(*env);
		(*env) = tmp;
	}
	free(*env);
	if (pipes)
		ft_free_all(pipes, ft_liss_len(main_struct->p_fitst));
	ft_p_list_clear(main_struct->p_fitst);
	return (pid);
}
