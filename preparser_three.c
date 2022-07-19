/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:36:13 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/19 00:58:16 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_redir_one(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>' && str[i + 1] != '\0' \
		&& str[i + 2] == '>' && str[i + 2] != '\0')
	{
		if (str[i + 3] != '\0' && str[i + 3] == '>')
		{
			printf("Syntax error near unexpected token '>>'\n");
			return (1);
		}
		printf("Syntax error near unexpected token '>'\n");
		return (1);
	}
	if (str[i] == '<' && str[i + 1] == '<' && str[i + 1] != '\0' \
		&& str[i + 2] == '<' && str[i + 2] != '\0')
	{
		if (str[i + 3] != '\0' && str[i + 3] == '<')
		{
			printf("Syntax error near unexpected token '<<'\n");
			return (1);
		}
		printf("Syntax error near unexpected token '<'\n");
		return (1);
	}
	return (0);
}

int	pre_redir_two(char *str, int i, int drop)
{
	if (str[i] == '>' || str[i] == '<')
	{
		drop = drop_null(str, i + 1, '>');
		if (drop != 0)
		{
			if (drop == 1)
				printf("Syntax error near unexpected token '>'\n");
			if (drop == 2)
				printf("Syntax error near unexpected token '>>'\n");
			return (1);
		}
		drop = drop_null(str, i + 1, '<');
		if (drop != 0)
		{
			if (drop == 1)
				printf("Syntax error near unexpected token '<'\n");
			if (drop == 2)
				printf("Syntax error near unexpected token '<<'\n");
			return (1);
		}
		return (0);
	}
	return (0);
}

int	pre_pipe(char *str, int i)
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
		if (drop_null(str, i + 1, '|'))
		{
			printf("Syntax error near unexpected token '|'\n");
			return (1);
		}
	}
	return (0);
}

int	find_double(char *str, int i)
{
	int	drop;

	drop = 0;
	if (str[i] == '<' && str[i + 1] != '\0' && str[i + 1] == '>')
	{
		printf("Syntax error near unexpected token '<>'\n");
		return (1);
	}
	if (pre_redir_one(str, i))
		return (1);
	if (pre_redir_two(str, i, drop))
		return (1);
	if (pre_pipe(str, i))
		return (1);
	return (0);
}
