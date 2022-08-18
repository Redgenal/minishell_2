/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:04:40 by utawana           #+#    #+#             */
/*   Updated: 2022/05/19 20:04:42 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

pid_t	ft_obrabotka(char **str, char **envp)
{
	pid_t	pid;
	char	**cmd;
	DIR		*dir;

	dir = NULL;
	pid = fork();
	if (pid < 0)
		ft_call_exit("Error");
	else if (pid == 0)
	{
		dir = opendir(str[0]);
		if (dir && str[0][0] == '.')
			ft_is_a_dir(str[0]);
		cmd = ft_change_cmd(str, envp);
		execve(cmd[0], cmd, envp);
		ft_call_cant_exe(cmd[0]);
	}
	return (pid);
}

int	ft_for_buildins(char *com, t_list **env, char **arg)
{
	if (ft_strncmp(com, "cd", 3) == 0)
		return (ft_cd(arg[1], env));
	else if (ft_strncmp(com, "env", 4) == 0)
		return (ft_env(*env));
	else if (ft_strncmp(com, "export", 7) == 0)
		return (ft_export(env, arg));
	else if (ft_strncmp(com, "echo", 5) == 0)
		return (ft_echo(arg));
	else if (ft_strncmp(com, "exit", 5) == 0)
		return (ft_exit(arg[1], arg));
	else if (ft_strncmp(com, "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(com, "unset", 6) == 0)
		return (ft_unset(arg[1], env));
	else
		return (666);
}

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

void	ft_pipe_redir(int i, int **pipes, t_lis *p_one, int out)
{
	int	d1;
	int	d2;

	if (i < (ft_liss_len(p_one) - 1))
		pipe(pipes[i]);
	if (i == 0)
	{
		d2 = dup2(pipes[i][1], STDOUT_FILENO);
		if (d2 == -1)
			ft_call_exit("dup error");
		close(pipes[i][1]);
	}
	else if (i == (ft_liss_len(p_one) - 1))
	{
		d1 = dup2(pipes[i - 1][0], STDIN_FILENO);
		if (d1 == -1)
			ft_call_exit("dup2 error");
		close(pipes[i - 1][0]);
		d2 = dup2(out, 1);
		if (d2 == -1)
			ft_call_exit("dup error");
	}
	else
		ft_circle_pipes_redir(pipes, i);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (--i >= 0)
	{
		arr[i] = NULL;
	}
	if (arr != NULL)
		free(arr);
}

int	ft_error_return(pid_t pid, t_main *main_struct, int **pipes, t_list **env)
{
	dup2(main_struct->in, 0);
	dup2(main_struct->out, 1);
	while (*env)
	{
		free(*env);
		(*env) = (*env)->next;
	}
	if (pipes)
		ft_free_all(pipes, ft_liss_len(main_struct->p_fitst));
	return (pid);
}

int	ft_return(int status, t_main *main_struct)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (main_struct->status);
}

int	ft_main_job(t_main *main_struct, t_list **env, int **pipes, pid_t *pid)
{
	t_lis	*p_one;
	int		i;

	p_one = main_struct->p_list;
	i = 0;
	while (main_struct->p_list != NULL)
	{
		if ((ft_liss_len(p_one) != 1) && (i <= (ft_liss_len(p_one) - 1)))
			ft_pipe_redir(i, pipes, p_one, main_struct->out);
		sig_func();
		if (main_struct->p_list->redir != NULL)
			*pid = ft_dup_call(main_struct, env, main_struct->my_env);
		else
			*pid = ft_do_ur_job(main_struct, env, main_struct->my_env);
		if (*pid < 0)
			return (ft_error_return(*pid, main_struct, pipes, env));
		i++;
		main_struct->p_list = main_struct->p_list->next;
	}
	return (0);
}

//Разбить на функции, поиграть с переменными
int	main_exe(t_lis *p_list, t_main *main_struct)
{
	t_list	*env;
	int		**pipes;
	int		status;
	pid_t	pid;
	int		rez;

	env = NULL;
	pipes = NULL;
	status = 0;
	main_struct->p_list = p_list;
	main_struct->p_fitst = p_list;
	env = ft_create_env(main_struct->my_env);
	if (p_list->next != NULL)
	{
		pipes = ft_create_pipes(ft_liss_len(p_list));
		if (!pipes)
			return (1);
	}
	rez = ft_main_job(main_struct, &env, pipes, &pid);
	if (rez < 0)
		return (rez);
	ft_free_arr(main_struct->my_env);
	main_struct->my_env = ft_from_lists_to_str(env);
	waitpid(pid, &status, 0);
	ft_error_return(pid, main_struct, pipes, &env);
	return (ft_return(status, main_struct));
}
