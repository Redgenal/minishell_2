/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:28:49 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/20 19:58:33 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_start(char *str, int i, int len)
{	
	if (str[i] == '|')
	{
		if (str[i + 1] == '|' && len >= 1)
			printf("minishell: syntax error near unexpected token '||'\n");
		else
			printf("minishell: syntax error near unexpected token '|'\n");
		return (1);
	}
	if (str[i] == '<' && str[i + 1] == '<' && str[i + 1] != '\0')
	{
		if (str[i + 2] != '\0' && str[i + 2] == '<' && drop_space(str, 3) \
				&& str[i + 3] != '\0' && str[i + 3] != '<')
			printf("minishell: syntax error near unexpected token '<<<'\n");
		else if (str[i + 2] == '<' && str[i + 3] == '<' && str[i + 4] == '<')
			printf("minishell: syntax error near unexpected token '<<'\n");
		else if (str[i + 2] == '<' && str[i + 3] == '<')
			printf("minishell: syntax error near unexpected token '<'\n");
		else if (len >= 3 && drop_space(str, 2) && str[i + 2] != '<')
			return (0);
		else
			printf("minishell: syntax error near unexpected token 'newline'\n");
		return (1);
	}
	return (0);
}

void	pre_o_quote(char *str, int *i, int *o_flag)
{
	if (str[*i] == '\'' && !pre_slesh(str, *i))
	{
		*o_flag = *(o_flag) * (-1);
		(*i)++;
		while (str[*i] && str[*i] != '\'')
		{
			(*i)++;
		}
		if (str[*i] == '\'')
			*o_flag = *(o_flag) * (-1);
	}
}

void	pre_d_quote(char *str, int *i, int *d_flag)
{
	if (str[*i] == '\"' && !pre_slesh(str, *i))
	{
		*d_flag = *(d_flag) * (-1);
		(*i)++;
		while (str[*i] && str[*i] != '\"')
		{
			(*i)++;
			if (str[*i] == '\"' && pre_slesh(str, *i))
				(*i)++;
		}
		if (str[*i] == '\"')
			*d_flag = *(d_flag) * (-1);
	}
}

int	pre_quote(char *str, int len)
{
	int	i;
	int	o_flag;
	int	d_flag;

	o_flag = -1;
	d_flag = -1;
	i = 0;
	if (pre_start(str, i, len))
		return (1);
	while (str[i])
	{
		pre_o_quote(str, &i, &o_flag);
		pre_d_quote(str, &i, &d_flag);
		if (first_part(str, len, i))
			return (1);
		i++;
	}
	if (d_flag > 0 || o_flag > 0)
	{
		printf ("minishell: multi-line comment processing missing\n");
		return (1);
	}
	return (0);
}

int	ft_prepars(char *str)
{
	int	res;
	int	len;
	int	i;
	int	f;

	i = 0;
	f = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if(str[i] == ' ')
			f++;
		i++;
	}
	if(len == f)
		return(1);
	res = pre_quote(str, len);
	return (res);
}
