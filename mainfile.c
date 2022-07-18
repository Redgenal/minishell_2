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

pid_t	ft_obrabotka(char *str, char **envp)
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
		dir = opendir(str);
		if (dir && str[0] == '.')
			ft_is_a_dir(str);
		cmd = ft_delenie_cmd(str);
		cmd = ft_change_cmd(cmd, envp);
		execve(cmd[0], cmd, envp);
		ft_call_cant_exe(cmd[0]);
	}
	return (pid);
}

int	ft_for_buildins(char *com, t_list **env, char **arg)
{
	if (ft_strncmp(com, "cd", 3) == 0)
		return (ft_cd(arg[0], env));
	else if (ft_strncmp(com, "env", 4) == 0)
		return (ft_env(*env));
	else if (ft_strncmp(com, "export", 7) == 0)
		return (ft_export(env, NULL));
	else if (ft_strncmp(com, "echo", 5) == 0)
		return (ft_echo(arg[0], arg[1]));
	else if (ft_strncmp(com, "exit", 5) == 0)
		return (ft_exit(arg[0], arg));
	else if (ft_strncmp(com, "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(com, "unset", 6) == 0)
		return (ft_unset(arg[0], env));
	else
		return (666);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_list	*list;
	int		i;
	char	**my_env;

	i = 0;
	env = NULL;
	(void) argc;
	while (envp[i])
		i++;
	i = -1;
	while (envp[++i] != NULL)
	{
		list = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, list);
	}
	list = ft_lstnew(NULL);
	ft_lstadd_back(&env, list);
	if (ft_for_buildins("Desktop", &env, argv) == 666)
	{
		my_env = ft_from_lists_to_str(env);
		ft_obrabotka("pipex", my_env);
	}
	// ft_env(env);
	// ft_export(&env, "A=hello");
	// ft_pwd();
	// ft_cd("/Users/utawana", &env);
	// ft_env(env);
	// ft_export(&env, NULL);
	// printf("%d\n", ft_exit(argv[1], argv));
	return (0);
}
