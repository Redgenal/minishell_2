/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:08:41 by utawana           #+#    #+#             */
/*   Updated: 2022/07/11 16:08:43 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**ft_from_lists_to_str(t_list *env)
{
	char	**envp;
	int		i;
	int		j;

	i = ft_lists_len(env);
	envp = malloc(sizeof(char *) * (i + 1));
	j = -1;
	while (++j < i)
	{
		envp[j] = malloc(sizeof(char) * (ft_strlen(env->content) + 1));
		envp[j] = ft_memcpy(envp[j], env->content, ft_strlen(env->content) + 1);
		if (env->next)
			env = env->next;
	}
	envp[j] = NULL;
	return (envp);
}

void	ft_child_func(char **buff, int *pip, char *stop)
{
	while (*buff != NULL)
	{
		sig_heredoc();
		free(*buff);
		write(1, "> ", 2);
		*buff = get_next_line(0);
		if (!(*buff))
			exit(-1);
		if (ft_strncmp(*buff, stop, ft_strlen(stop) + 1) == 0)
			break ;
		write(*pip, *buff, ft_strlen(*buff));
		write(*pip, "\n", 1);
	}
	exit(0);
}

int	ft_here_doc(char *stop)
{
	int		pip[2];
	char	*buff;
	pid_t	pid;
	int		status;

	buff = malloc(sizeof(*buff));
	pipe(pip);
	sig_ignore();
	pid = fork();
	if (pid < 0)
		perror("Pipe error: ");
	else if (pid == 0)
		ft_child_func(&buff, &pip[1], stop);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == 11)
		return (-1);
	if (buff)
		free(buff);
	close(pip[1]);
	return (pip[0]);
}

int	ft_liss_len(t_lis *env)
{
	int	i;

	i = 1;
	while (env->next)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
