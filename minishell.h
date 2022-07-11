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
# include <stdio.h>

int		ft_env(t_list *env);
int		ft_export(t_list **env, char *str);
int		ft_pwd(void);
int		ft_cd(char *str, t_list **env);
int		ft_echo(char *str, int flag);
int		ft_unset(char *str, t_list **env);
int		ft_exit(char *str, char **strs);

int		ft_ret_code(int value, char *str);

#endif
