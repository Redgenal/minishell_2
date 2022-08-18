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

int	ft_echo(char **args)
{
	int	i;

	i = 0;
	if (args[1] != NULL && ft_strncmp(args[1], "-n", 3) == 0)
	{
		i++;
		while (args[++i])
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
		}
	}
	else
	{
		while (args[++i])
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
		}
		printf("\n");
	}
	return (0);
}
