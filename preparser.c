/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:28:49 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/13 20:33:23 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pre_end_slesh (char *str, int len)
{
	int j;

	j = 0;
	while (len >= 1 && str[len - 1])
	{
		len--;
		j++;
	}
	if (j%2 == 0)
		return (0);
	return(1);
}

int pre_slesh (char *str, int i)
{
	int j;

	j = 0;
	i--;
	while(str[i] == '\\' && i >= 0)
	{	
		j++;
		i--;
	}
	if (j % 2 == 0)
		return(0);
	return (1);
}


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

int	find_double(char *str, int j)
{
	int	i;
	int	drop;

	drop = 0;
	i = j;
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

int	first_part(char *str, int len, int i)
{
	if ((str[len - 1] == '>' || str[len - 1] == '<' \
		|| (str[len - 1] == '>' && str[len - 2] == '>' && len >= 2) \
		|| (str[len - 1] == '<' && str[len - 2] == '<' && len >= 2)))
	{
			printf("Syntax error near unexpected token 'newline'\n");
			return (1);
	}
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
	
	if (find_double(str, i))
		return (1);

	return (0);
}

int	pre_quote(char *str)
{
	int	i;
	int	o_flag;
	int	d_flag;
	int len;
	int res;

	len = ft_strlen(str);
	res = 0;
	o_flag = -1;
	d_flag = -1;
	i = 0;
	if (str[i] == '|')
	{
		if (str[i + 1] == '|' && len >= 1)
		{
			printf("Syntax error near unexpected token '||'\n");
			return (1);
		}
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

		if (str[i] == '\'' && !pre_slesh(str, i))
		{
			o_flag = -(o_flag);
			i++;
			while (str[i] && str[i] != '\'')
			{
				i++;
				if (str[i] == '\'' && pre_slesh(str, i))
					i++;
			}
			if (str[i] == '\'')
				o_flag = -(o_flag);
		}
		if (str[i] == '\"' && !pre_slesh(str, i))
		{
			d_flag = -(d_flag);
			i++;
			while (str[i] && str[i] != '\"')
			{
				i++;
				if (str[i] == '\"' && pre_slesh(str, i))
					i++;
			}
			if (str[i] == '\"')
				d_flag = -(d_flag);
		}
		res = first_part(str, len, i);
		if (res == 1)
			return (1);
		i++;
	}
	if (d_flag > 0 || o_flag > 0)
	{
		printf ("Multi-line comment processing missing\n");
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
	res = pre_quote(str);
	return (res);
}

//Обработать сom >>>     com>>>>    com <<<<    com <<<<<
// Добавить pre_end_slesh для обработки слеша в конце
