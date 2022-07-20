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

typedef struct	s_redir
{
    int				type;
	char			*file;
    struct s_redir	*next;
}	p_redir;

typedef struct	s_lis
{
    char			**args;
    struct s_lis	*next;
	p_redir			*redir;
}	p_lis;

int		ft_env(t_list *env);
int		ft_export(t_list **env, char *str);
int		ft_pwd(void);
int		ft_cd(char *str, t_list **env);
int		ft_echo(char *str, char *flag);
int		ft_unset(char *str, t_list **env);
int		ft_exit(char *str, char **strs);

int		ft_lists_len(t_list *env);

char	**ft_from_lists_to_str(t_list *env);

#endif
