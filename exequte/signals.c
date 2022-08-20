/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:29:46 by utawana           #+#    #+#             */
/*   Updated: 2022/08/17 17:51:34 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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

void	sig_ignore(void)
{
	struct sigaction	sig;
	struct sigaction	quit;

	sig.sa_handler = sig_inta;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	quit.sa_handler = SIG_IGN;
	sigemptyset(&quit.sa_mask);
	quit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &quit, NULL);
}
