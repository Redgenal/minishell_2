/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:29:46 by utawana           #+#    #+#             */
/*   Updated: 2022/08/16 21:23:59 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	sig_inti(int sig)
{
	printf("^C\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	(void)sig;
}

void	sig_intie(int sig)
{
	printf("^\\Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	(void)sig;
}

void	sig_kill(int sig)
{
	exit(1);
	(void)sig;
}

void	sig_func(void)
{
	struct sigaction	sig;
	struct sigaction	quit;

	sig.sa_handler = sig_inti;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	quit.sa_handler = sig_intie;
	sigemptyset(&quit.sa_mask);
	quit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &quit, NULL);
}

void	sig_main(void)
{
	struct sigaction	sig;
	struct sigaction	quit;

	sig.sa_handler = sig_int;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	quit.sa_handler = SIG_IGN;
	sigemptyset(&quit.sa_mask);
	quit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &quit, NULL);
}

void	sig_heredoc(void)
{
	struct sigaction	sig;
	struct sigaction	quit;

	sig.sa_handler = sig_kill;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	quit.sa_handler = SIG_IGN;
	sigemptyset(&quit.sa_mask);
	quit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &quit, NULL);
}
