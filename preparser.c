/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:28:49 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/12 21:13:09 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	pre_quote(char *str)
// {
// 	int	i;
// 	int	k;
// 	int	j;

// 	i = 1;
// 	k = 0;
// 	j = 0;
// 	if (str[0] == '\'')
// 		k ++;
// 	if (str[0] == '\"')
// 		j++;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'' && str[i - 1] != '\\')
// 			k++;
// 		if (str[i] == '\"' && str[i - 1] != '\\')
// 			j++;
// 		i++;
// 	}
// 	if (k % 2 != 0 && k > 0)
// 	{

// 	}
// 		return (1);
// 	else
// 		return (0);
// }

// int	pre_quote(char *str)
// {
// 	int	i;
// 	int	o_flag;
// 	int	d_flag;

// 	o_flag = -1;
// 	d_flag = -1;
// 	i = 1;
// 	if (str[0] == '\'')
// 		o_flag = -(o_flag);
// 	if (str[0] == '\"')
// 		d_flag = -(d_flag);
// 	while (str[i])
// 	{
// 		if(
// 	}
	
// }
int	drop_null(char *str, int i, char c)
{
	if (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		if (ft_isalnum(str[i]) || str[i] == '$' || str[i] == '?')
			return (0);
		i++;
	}
	if (str[i + 1] != '\0' && str[i + 1] == c)
		return (2);
	return (1);
}

int	find_double(char *str)
{
	int	i;
	int	drop;

	i = 0;
	drop = 0;


	if (str[i] == '|' && str[i + 1] != '|' && str[i + 1] != '\0')
	{
		printf("Syntax error near unexpected token '|'\n");
		return (1);
	}


	if (str[i] == '<' && str[i + 1] == '<' && str[i + 1] != '\0')
	{
		printf("Multi-line comment processing missing\n");
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

		if (str[i] == '<' && str[i + 1] != '\0' && str[i + 1] == '>')
		{
			printf("Syntax error near unexpected token '<>'\n");
			return (1);
		}

		if (str[i] == '>' || str[i] == '<')
		{
			drop = drop_null(str, i + 1, '>');
			if (drop == 1)
			{
				printf("Syntax error near unexpected token '>'\n");
				return (1);
			}
			if (drop == 2)
			{
				printf("Syntax error near unexpected token '>>'\n");
				return (1);
			}
			drop = drop_null(str, i + 1, '<');
			if (drop == 1)
			{
				printf("Syntax error near unexpected token '<'\n");
				return (1);
			}
			if (drop == 2)
			{
				printf("Syntax error near unexpected token '<<'\n");
				return (1);
			}
		}

		if (str[i] == '|')
		{
			if (drop_null(str, i + 1, '|'))
			{
				printf("Multi-line comment processing missing\n");
				return (1);
			}
		}


		i++;
	}
	return (0);
}

int	first_part(char *str, int len)
{
	if (pre_quote(str))
		return (1);
	if ((str[len - 1] == '>' || str[len - 1] == '<' \
		|| (str[len - 1] == '>' && str[len - 2] == '>' && len >= 2) \
		|| (str[len - 1] == '<' && str[len - 2] == '<' && len >= 2)))
	{
		if (!(len >= 3 && (str[len - 3] == '>' || str[len - 3] == '<')))
		{
			printf("Syntax error near unexpected token 'newline'\n");
			return (1);
		}
	}
	if (find_double(str))
		return (1);

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
