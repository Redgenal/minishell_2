/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:52:15 by utawana           #+#    #+#             */
/*   Updated: 2022/08/17 19:26:55 by utawana          ###   ########.fr       */
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
	exit(11);
	(void)sig;
}

void	sig_inta(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	(void)sig;
}
