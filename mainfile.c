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

	pid = fork();
	if (pid < 0)
		ft_call_exit();
	else if (pid == 0)
	{
		cmd = ft_delenie_cmd(str);
		cmd = ft_change_cmd(cmd, envp);
		execve(cmd[0], cmd, envp);
		ft_call_cant_exe();
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_list	*list;
	int		i;
	char	**my_env;

	i = 0;
	env = NULL;
	(void) argv;
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
	my_env = ft_from_lists_to_str(env);
	ft_obrabotka("ls -l", my_env);
	// ft_env(env);
	// ft_export(&env, "A=hello");
	// ft_pwd();
	// ft_cd("/Users/utawana", &env);
	// ft_env(env);
	// ft_export(&env, NULL);
	// printf("%d\n", ft_exit(argv[1], argv));
	return (0);
}
