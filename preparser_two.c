/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:21:40 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/02 11:29:57 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_end_one(char *str, int len)
{
	if (str[len - 3] == '>' && len >= 3)
	{
		if (str[len - 4] == '>' && len >= 4)
		{
			printf("Syntax error near unexpected token '>>'\n");
			return (1);
		}
		printf("Syntax error near unexpected token '>'\n");
		return (1);
	}
	if (str[len - 3] == '<' && str[len - 4] == '<' && len >= 4)
	{
		if (str[len - 5] == '<' && len >= 5)
		{
			printf("Syntax error near unexpected token '<<'\n");
			return (1);
		}
		printf("Syntax error near unexpected token '<'\n");
		return (1);
	}
	return (0);
}

int	pre_end_two(char *str, int len)
{
	if (str[len - 1] == '|' || (str[len - 1] == '|' && str[len - 2] != '|'))
	{
		if (len >= 3 && str[len - 3] != '|')
		{	
			printf("Multi-line comment processing missing\n");
			return (1);
		}
		if (len >= 3 && str[len - 3] == '|')
		{	
			if (len >= 4 && str[len - 4] == '|')
			{
				printf("Syntax error near unexpected token '||'\n");
				return (1);
			}
			printf("Syntax error near unexpected token '|'\n");
			return (1);
		}
	}
	return (0);
}

int	first_part(char *str, int len, int i)
{
	if ((str[len - 1] == '>' || str[len - 1] == '<' \
		|| (str[len - 1] == '>' && str[len - 2] == '>' && len >= 2) \
		|| (str[len - 1] == '<' && str[len - 2] == '<' && len >= 2)))
	{
		if (pre_end_one(str, len))
			return (1);
		printf("Syntax error near unexpected token 'newline'\n");
		return (1);
	}
	if (pre_end_two(str, len))
		return (1);
	if (pre_end_slesh(str, len))
	{
		printf("Multi-line comment processing missing\n");
		return (1);
	}
	if (find_double(str, i))
		return (1);
	return (0);
}
