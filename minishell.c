/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:11:45 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/19 17:40:35 by gantedil         ###   ########.fr       */
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

int	minishell(t_main *main_struct)
{
	char	*str;

	str = NULL;
	while (1)
	{
		sig_main();
		str = readline(PROMPT);
		if (str && str[0] != '\0')
			add_history(str);
		if (!str)
		{
			printf("\033[A%sexit\n", PROMPT);
			return (0);
		}
		if (!ft_prepars(str))
			main_struct->status = ft_parser(str, main_struct);
		else
			main_struct->status = 258;
		free (str);
	}
	free(main_struct);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	struct termios	p;
	t_main			*main_struct;
	t_list			*enve;

	tcgetattr(0, &p);
	main_struct = (t_main *) malloc (sizeof(*main_struct));
	main_struct->out = dup(STDOUT_FILENO);
	main_struct->in = dup(STDIN_FILENO);
	main_struct->status = 0;
	enve = ft_create_env(env);
	main_struct->my_env = ft_from_lists_to_str(enve);
	p.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, 0, &p);
	(void)argv;
	if (argc > 1)
	{
		printf("%s\n", "The programm must not have arguments");
		return (1);
	}
	return (minishell(main_struct));
}
