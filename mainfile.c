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

#include "minishell.h"

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
		return (ft_export(env, arg[1]));
	else if (ft_strncmp(com, "echo", 5) == 0)
		return (ft_echo(arg[1], arg[2]));
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
	while (envp[++i] != NULL)
	{
		list = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, list);
	}
	list = ft_lstnew(NULL);
	ft_lstadd_back(&env, list);
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

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	int		i;
	char	**my_env;
	int		**pipes;
	int		status;
	// pid_t	pid;
	t_lis	*p_list;
	t_lis	*p_one;
	int		out;
	int		in;
	// int d1;
	// int d2;

	env = NULL;
	pipes = NULL;
	(void) argc;
	(void) argv;
	i = -1;
	p_list = (t_lis *) malloc(sizeof(*p_list));
	if (!p_list)
		return (0);
	p_list->args = malloc(sizeof(char *) * 3);
	p_list->args[0] = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	ft_strlcpy(p_list->args[0], argv[1], (ft_strlen(argv[1]) + 1));
	p_list->args[1] = malloc(sizeof(char) * (ft_strlen(argv[2]) + 1));
	ft_strlcpy(p_list->args[1], argv[2], (ft_strlen(argv[2]) + 1));
	p_list->args[2] = NULL;
	p_list->redir = NULL;
	// p_list->next = NULL;
	// p_list->redir = (t_redir *) malloc(sizeof(*p_list->redir));
	// p_list->redir->file = "2.txt";
	// p_list->redir->type = 1;
	// p_list->redir->next = NULL;
	// p_list->redir->next = (t_redir *) malloc(sizeof(*p_list->redir));
	// p_list->redir->next->file = "4.txt";
	// p_list->redir->next->type = 1;
	// p_list->redir->next->next = NULL;
	//
	p_list->next = (t_lis *) malloc(sizeof(*p_list));
	p_list->next->args = malloc(sizeof(char *) * 3);
	p_list->next->args[0] = malloc(sizeof(char) * (ft_strlen(argv[3]) + 1));
	ft_strlcpy(p_list->next->args[0], argv[3], (ft_strlen(argv[3]) + 1));
	p_list->next->args[1] = malloc(sizeof(char) * (ft_strlen(argv[4]) + 1));
	ft_strlcpy(p_list->next->args[1], argv[4], (ft_strlen(argv[4]) + 1));
	p_list->next->args[2] = NULL;
	p_list->next->next = NULL;
	p_list->next->redir = NULL;
	env = ft_create_env(envp);
	my_env = ft_from_lists_to_str(env);
	p_one = p_list;
	if (p_list->next != NULL)
	{
		pipes = ft_create_pipes(ft_liss_len(p_list));
		if (!pipes)
			return (1);
	}
	i = 0;
	out = dup(STDOUT_FILENO);
	in = dup(STDIN_FILENO);
	while (p_list != NULL)
	{
		if (i <= (ft_liss_len(p_one) - 1))
			ft_pipe_redir(i, pipes, p_one, out);
		if (p_list->redir != NULL)
			status = ft_dup_call(p_list, &env, my_env);
		else
			status = ft_do_ur_job(p_list, &env, my_env);
		i++;
		p_list = p_list->next;
	}
	// waitpid(pid, &status, 0);
	if (pipes)
		ft_free_all(pipes, ft_liss_len(p_one));
	return (WEXITSTATUS(status));
}
