#ifndef MINISHELL_H
#define MINISHELL_H

#define PROMPT "minishell $ "

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

void rl_replace_line();

int	minishell(void);
void	sig_int(int sig);

#endif