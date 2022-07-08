/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:28:49 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/08 23:52:18 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_quote(char *str)
{
	int	i;
	int	k;
	int	j;

	i = 1;
	k = 0;
	j = 0;
	if (str[0] == '\'')
		k ++;
	if (str[0] == '\"')
		j++;
	while (str[i])
	{
		if (str[i] == '\'' && str[i - 1] != '\\')
			k++;
		if (str[i] == '\"' && str[i - 1] != '\\')
			j++;
		i++;
	}
	if ((k % 2 != 0 || j % 2 != 0) && (k > 0 || j > 0))
		return (1);
	else
		return (0);
}

int	drop_pipe(char *str, int i)
{
	while (str[i] && str[i] != '|')
	{
		if (ft_isalnum(str[i]) || str[i] == '$' || str[i] == '?')
			return (0);
		i++;
	}
	return (1);
}

int	find_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|' && str[i + 1] != '|' && str[i + 1] != '\0')
	{
		printf("Syntax error near unexpected token '|'\n");
		return (1);
	}
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|' && str[i + 1] != '\0')
		{
			if (str[i + 2] != '\0' && str[i + 2] == '|')
			{
				printf("Syntax error near unexpected token '||'\n");
				return (1);
			}
			printf("Missing || command processing\n");
			return (1);
		}
		if (str[i] == '|')
		{
			if (drop_pipe(str, i + 1))
			{
				printf("Syntax error near unexpected token '|'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	first_part(char *str, int len)
{
	if (find_double(str))
		return (1);
	if (pre_quote(str))
		return (1);
	if (str[len - 1] == '>' || str[len - 1] == '<' \
		|| (str[len - 1] == '>' && str[len - 2] == '>') \
		|| (str[len - 1] == '<' && str[len - 2] == '<'))
	{
		printf("Syntax error near unexpected token 'newline'\n");
		return (1);
	}
	return (0);
}

int	ft_prepars(char *str)
{
	int	i;
	int	len;
	int	res;

	i = 0;
	len = ft_strlen(str);
	res = first_part(str, len);
	return (res);
}
