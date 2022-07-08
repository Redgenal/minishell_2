/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:11:45 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/05 23:52:45 by gantedil         ###   ########.fr       */
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

int	minishell(void)
{
	char	*str;

	while (1)
	{
		str = readline(PROMPT);
		if (str && str[0] != '\0')
			add_history(str);
		if (!str)
		{
			printf("\033[A%sexit\n", PROMPT);
			return (0);
		}
		free (str);
	}
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
	return (minishell());
}