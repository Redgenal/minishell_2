/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:58:18 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/29 20:48:09 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell$ "

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/headers/libft.h"

//void	rl_replace_line(char *c, int i);
int		minishell(char **env);
void	sig_int(int sig);
int		ft_prepars(char *str);
int		pre_end_slesh(char *str, int len);
int		drop_space(char *str, int i);
int		pre_slesh(char *str, int i);
int		drop_null(char *str, int i, char c);
int		first_part(char *str, int len, int i);
int		pre_end_two(char *str, int len);
int		pre_end_one(char *str, int len);
int		find_double(char *str, int i);
int		pre_pipe(char *str, int i);
int		pre_redir_two(char *str, int i, int drop);
int		pre_redir_one(char *str, int i);
int		pre_start(char *str, int i, int len);
int		pre_quote(char *str, int len);
void	pre_o_quote(char *str, int *i, int *o_flag);
void	pre_d_quote(char *str, int *i, int *d_flag);
int		ft_parser(char *str, char **env);

char	*s_quote(char *str, int *i);
char	*ft_slesh(char *str, int *i);
char	*d_quote(char *str, int *i, char **env);
char	*ft_drop_slesh(char *str, int *i);
int		ft_count_slesh(char *str, int i);
char	*ft_parse_slesh(char *str, int *i);
char	*ft_mini_slesh(char *str, int *i);
char	*ft_dollar(char *str, int *i, char **env);
char	*ft_get_dollar(char *str, int *i, char **env, int *flag);
char	*ft_split_dollar(char *str, int *i, char **env);
char	**ft_split_custom(char *s, char c);
int		count_d_quote(char *str, int i);

#endif