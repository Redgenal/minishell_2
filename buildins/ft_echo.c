/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:55:52 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:55:54 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_echo(char *str, char *flag)
{
	if (flag != NULL && ft_strncmp(flag, "-n", 3) == 0)
		printf("%s", str);
	else
		printf("%s\n", str);
	return (0);
}
