/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:04:48 by utawana           #+#    #+#             */
/*   Updated: 2022/05/19 20:04:50 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "pipex/pipex_bonus.h"
# include <stdio.h>
# include <dirent.h>

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

int		ft_env(t_list *env);
int		ft_export(t_list **env, char *str);
int		ft_pwd(void);
int		ft_cd(char *str, t_list **env);
int		ft_echo(char *str, char *flag);
int		ft_unset(char *str, t_list **env);
int		ft_exit(char *str, char **strs);

int		ft_call_file_not_found(char *str);
int		ft_is_a_dire(char *str);
int		ft_perm_denied(char *str);

int		ft_here_doc(char *stop);
int		ft_lists_len(t_list *env);
int		ft_liss_len(t_lis *env);

int		ft_dup_call(t_lis *p_list, t_list **env, char **my_env);
int		ft_for_buildins(char *com, t_list **env, char **arg);
int		ft_do_ur_job(t_lis *p_list, t_list **env, char **my_env);

char	**ft_from_lists_to_str(t_list *env);

pid_t	ft_obrabotka(char **str, char **envp);

#endif
