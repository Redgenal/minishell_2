/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:59:08 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/02 11:30:05 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_end_slesh(char *str, int len)
{
	int	j;

	j = 0;
	while (len >= 1 && str[len - 1] == '\\')
	{
		len--;
		j++;
	}
	if (j % 2 == 0)
		return (0);
	return (1);
}

int	drop_space(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	pre_slesh(char *str, int i)
{
	int	j;

	j = 0;
	if (i != 0)
		i--;
	while (str[i] == '\\' && i >= 0)
	{	
		j++;
		i--;
	}
	if (j % 2 == 0)
		return (0);
	return (1);
}

int	drop_null(char *str, int i, char c)
{
	if (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		if (ft_isalnum(str[i]) || str[i] == '$' \
		|| str[i] == '?' || str[i] == '\'' || str[i] == '\"')
			return (0);
		i++;
	}
	if (str[i + 1] != '\0' && str[i + 1] == c)
		return (2);
	return (1);
}
