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

int		ft_env(char **env);
int		ft_export(char **env, char *str);
int		ft_pwd();
int		ft_cd(char *str, char **env);
int 	ft_echo(char *str, int flag);

#endif
