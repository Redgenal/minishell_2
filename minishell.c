/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:11:45 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/16 02:46:39 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_int(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	(void)sig;
}

int	minishell(char **env)
{
	char	*str;
	int		pre;

	while (1)
	{
		pre = 0;
		str = readline(PROMPT);
		if (str && str[0] != '\0')
			add_history(str);
		if (!str)
		{
			printf("\033[A%sexit\n", PROMPT);
			return (0);
		}
		pre = ft_prepars(str);
		if (!pre)
		{
			ft_parser(str, env);
		}
		free (str);
	}
	free (str);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	struct termios	p;

	tcgetattr(0, &p);
	p.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, 0, &p);
	argv = NULL;
	env = NULL;
	if (argc > 1)
	{
		printf("%s\n", "The programm must not have arguments");
		return (1);
	}
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, SIG_IGN);
	return (minishell(env));
}
