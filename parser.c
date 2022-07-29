/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:29:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/29 20:59:59 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_of_pipes(char *str)
{
	int	i;
	int	count;
	int	o_flag;
	int	d_flag;

	o_flag = -1;
	d_flag = -1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (o_flag < 0 && d_flag < 0 && str[i] == '|')
			count ++;
		i++;
	}
	return (count);
}

char	*get_full_str(char *str, int *i)
{
	int		o_flag;
	int		d_flag;
	char	*tmp;
	int		j;

	o_flag = -1;
	d_flag = -1;
	tmp = NULL;
	j = *i;
	while (str[*i] && str[*i] != '|')
	{
		pre_o_quote(str, i, &o_flag);
		pre_d_quote(str, i, &d_flag);
		(*i)++;
	}
	tmp = ft_substr(str, j, *i - j);
	return (tmp);
}

int	count_d_quote(char *str, int i)
{
	while (str[i] && str[i] != '\"')
	{
		if (str[i] != '\"')
			i++;
		if (str[i] == '\"' && !ft_count_slesh(str, i))
			i++;
	}
	return (i);
}

int	get_count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] != '<' && str[i] != '>')
		count++;
	while (str[i])
	{
		if (str[i] == '\"' && ft_count_slesh(str, i))
		{
			i++;
			i = count_d_quote(str, i);
		}
		if (str[i] == '\'' && ft_count_slesh(str, i))
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
		}
		if (str[i] == '>' || str[i] == '<')
		{
			count++;
			if (str[i + 1] == '>' || str[i + 1] == '<')
				i++;
			if (str[i + 1] != '\0' && str[i + 1] != ' ' && str[i + 1] != '\t')
				count++;
		}
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0' \
			&& str[i + 1] != '>' && str[i + 1] != '<')
			count++;
		i++;
	}
	return (count);
}

char	**get_list_words(char *str)
{
	// char	**result;
	// int		i;
	// int		j;
	// int		start;

	// if (!str)
	// 	return (0);
	// result = (char **) malloc(sizeof(char *) * (get_count_words(str) + 1));
	// i = 0;
	// j = 0;
	// if (!result)
	// 	return (0);
	// while (str[i] && str[i] == ' ')
	// 	i++;
	// start = i;
	// while (str[i])
	// {
	// 	if (str)
	// 	result[j] = ft_substr(str, i, )
	// }
	
    // // Дописать получение каждой строки
	// return (result);
}

char	**get_list_str(char *str)
{
	int		i;
	int		j;
	int		count_pipe;
	char	**param;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	count_pipe = ft_count_of_pipes(str);
	param = (char **) malloc (sizeof(char *) * (count_pipe + 2));
	if (!param)
		return (0);
	while (str[i] && j < (count_pipe + 1))
	{
		param[j] = get_full_str(str, &i);
		i++;
		j++;
	}
	param[j] = NULL;
	return (param);
// 	i = 0;
// 	j = 0;
// 	while (i < count_pipe + 1)
// 	{
// 	 	j = 0;
// 	 	while (param[i] != NULL && param[i][j] != '\0')
// 	 	{
// //			printf("start_symb = %c\n", param[i][j]);
// 			if (param[i][j] == '\"')
// 				param[i] = d_quote(param[i], &j, env);
// 			if (param[i][j] == '\'')
// 				param[i] = s_quote(param[i], &j);
// 			if (param[i][j] == '$')
// 				param[i] = ft_split_dollar(param[i], &j, env);
// 			if (param[i][j] == '\\')
// 				param[i] = ft_slesh(param[i], &j);
// 			if (param[i][j] == '\\' )
// 				param[i] = ft_drop_slesh(param[i], &j);
// 			if (param[i][j])
// 	 			j++;
// 	 	}
// 	 	i ++;
// 	}
// 	i = 0;
// 	while (param[i])
// 	{
// 		printf("str = %s\n", param[i]);
// 		i++;
// 	}
//	ft_parse_str(param);
}

int	ft_parser(char *str, char **env)
{
	int		i;
	int 	j;
	int		count_param;
	char	**pipes_strs;
	char	***blocks;

	count_param = 0;
	pipes_strs = get_list_str(str);
	i = 0;
	(void)env;
	while (pipes_strs[i])
	{
		printf("pip_str = %s\n",pipes_strs[i]);
		count_param++;
		i++;
	}
	i = 0;
	blocks = (char ***) malloc(sizeof(char **) * count_param);
	while (i <= count_param)
	{
		j = 0;
		blocks[i] = get_list_words(pipes_strs[i]);
		while (blocks[i][j])
		{
			printf("str = %s\n", blocks[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
