/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:58:18 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 17:36:43 by utawana          ###   ########.fr       */
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
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/headers/libft.h"
# include "../pipex/headers/pipex_bonus.h"

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_lis
{
	char			**args;
	struct s_lis	*next;
	t_redir			*redir;
}	t_lis;

typedef struct s_words
{
	char			**result;
	int				i;
	int				j;
	int				start;
}	t_words;

typedef struct s_main
{
	int		in;
	int		out;
	t_lis	*p_list;
	int		status;
	char	**my_env;
}	t_main;

//parser

//void	rl_replace_line(char *c, int i);
int		minishell(t_main *main_stuct);
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
int		ft_parser(char *str, t_main *main_stuct);

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
char	*ft_get_env_name(char *str, int *i);
int		count_d_quote(char *str, int i);
int		find_end_slesh(char *str, int *j);
int		get_count_words(char *str);
char	**get_list_words(char *str);
char	**get_list_str(char *str);
char	*parse_word(char *param, char **env);
char	*get_full_str(char *str, int *i);
int		ft_count_of_pipes(char *str);

t_redir	*get_list_redir(char **envp);
t_redir	*ft_redirlast(t_redir *lst);
t_redir	*ft_redirnew(void *type, void *content);
void	ft_rediradd_back(t_redir **lst, t_redir *new);
void	ft_lisadd_back(t_lis **lst, t_lis *new);
t_lis	*ft_lislast(t_lis *lst);
t_lis	*create_list(char ***blocks, int count_blocks);
int		get_redir(char *str);
int		count_args(char **words);
char	**get_args(char **words);
int		count_redir(char **words);

int		com_parser_api(char ***blocks, int count_blocks, t_main *main_stuct);

//coms

int		ft_env(t_list *env);
int		ft_export(t_list **env, char *str);
int		ft_pwd(void);
int		ft_cd(char *str, t_list **env);
int		ft_echo(char *str, char *flag);
int		ft_unset(char *str, t_list **env);
int		ft_exit(char *str, char **strs);

int		ft_call_file_not_found(t_main *m_s, char *str);
int		ft_is_a_dire(t_main *m_s, char *str);
int		ft_perm_denied(t_main *m_s, char *str);

int		ft_here_doc(char *stop);
int		ft_lists_len(t_list *env);
int		ft_liss_len(t_lis *env);

int		ft_dup_call(t_main *m_s, t_list **env, char **my_env);
int		ft_for_buildins(char *com, t_list **env, char **arg);
int		ft_do_ur_job(t_main *m_s, t_list **env, char **my_env);
int		main_exe(t_lis *p_list, t_main *main_stuct);

char	**ft_from_lists_to_str(t_list *env);

pid_t	ft_obrabotka(char **str, char **envp);

t_list	*ft_create_env(char **envp);

#endif