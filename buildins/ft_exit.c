/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:09 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:10 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	ft_isstring(char *str)
{
	ft_putstr_fd("minishell$ exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (255);
}

int	ft_one_arg(int n, char *str)
{
	if (n == 0)
		return (ft_isstring(str));
	else
	{
		if (((str[0] != '-') && (ft_strlen(str) > 10))
			|| ((str[0] == '-') && (ft_strlen(str) > 11))
			|| ((ft_strncmp(str, "2147483647", 10) > 0)
				&& (ft_strlen(str) == 10))
			|| ((ft_strncmp(str, "-2147483648", 10) < 0)
				&& (ft_strlen(str) == 11)) || ft_check(str))
			return (ft_isstring(str));
		else
			return (n % 256);
	}
}

int	ft_exit(char *str, char **strs)
{
	int	n;

	if (!str)
		exit(0);
	n = ft_atoi(str);
	if (n == 0 && ft_isdigit(str[0]))
		exit(0);
	else
	{
		if (strs[2])
		{
			ft_putstr_fd("minishell$ exit: too many arguments\n", 2);
			exit(1);
		}
		else
			exit(ft_one_arg(n, str));
	}
}
