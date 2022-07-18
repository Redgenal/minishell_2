/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:29 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:30 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_ret_pwd_code(int value, char *str)
{
	if (str && (value == 0))
		ft_putstr_fd(str, 1);
	else if (str && (value == 1))
	{
		ft_putstr_fd("minishell: pwd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if ((value == 1) && !str)
		perror("minishell: cd: ");
	return (value);
}

int	ft_pwd(void)
{
	char	*my_path;

	my_path = getcwd(NULL, 1000);
	if (!my_path)
		return (ft_ret_pwd_code(1, NULL));
	printf("%s\n", my_path);
	free(my_path);
	return (0);
}
