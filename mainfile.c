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

// pid_t	ft_circle_function(int **pipes, int count, p_list, char **envp)
// {
// 	int		i;
// 	pid_t	pid;

// 	i = -1;
// 	count -= 1;
// 	while (++i <= count)
// 	{
// 		if (i < count)
// 			pipe(pipes[i]);
// 		if (i > 0)
// 			close(pipes[i - 1][1]);
// 		pid = fork();
// 		if (pid < 0)
// 			ft_call_exit("Error");
// 		else if (pid == 0)
// 		{
// 			if (i < count)
// 				count -= ft_choose_child(pipes, strs, envp, i);
// 			else
// 				ft_choose_last_child(pipes, strs, envp, i);
// 		}
// 		if (i > 0)
// 			close(pipes[i - 1][0]);
// 	}
// 	return (pid);
// }

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_list	*list;
	int		i;
	char	**my_env;
	// int		**pipes;
	int		status;
	// pid_t	pid;
	t_lis	*p_list;

	env = NULL;
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
	p_list->next = NULL;
	p_list->redir = (t_redir *) malloc(sizeof(*p_list->redir));
	p_list->redir->file = "4.txt";
	p_list->redir->type = 1;
	p_list->redir->next = (t_redir *) malloc(sizeof(*p_list->redir));
	p_list->redir->next->file = "2.txt";
	p_list->redir->next->type = 1;
	p_list->redir->next->next = NULL;
	while (envp[++i] != NULL)
	{
		list = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, list);
	}
	list = ft_lstnew(NULL);
	ft_lstadd_back(&env, list);
	my_env = ft_from_lists_to_str(env);
	while (p_list != NULL)
	{
		if (p_list->redir != NULL)
			status = ft_dup_call(p_list, &env, my_env);
		else
			if (ft_for_buildins(p_list->args[0], &env, p_list->args) == 666)
				ft_obrabotka(p_list->args, my_env);
		p_list = p_list->next;
	}
	// else
	// {
	// 	pipes = ft_create_pipes(ft_lists_len(p_list));
	// 	if (!pipes)
	// 		return (1);
	// 	pid = ft_circle_function(pipes, ft_lists_len(p_list), p_list, my_env);
	// 	ft_close_all(pipes, ft_lists_len(p_list));
	// 	waitpid(pid, &status, 0);
	// 	ft_free_all(pipes, ft_lists_len(p_list));
	// }
	return (WEXITSTATUS(status));
}
