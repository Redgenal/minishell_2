/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:29:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/22 16:29:41 by gantedil         ###   ########.fr       */
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
		//pre_o_quote(str, &i, &o_flag);
		//pre_d_quote(str, &i, &d_flag);
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
	tmp[*i - j + 1] = '\0';
	return (tmp);
}

// void ft_parse_str(char **param)
// {
	
// }

void	get_list_str(char *str, char **env)
{
	int		i;
	int		j;
	int		count_pipe;
	char	**param;
	
	i = 0;
	j = 0;
	count_pipe = ft_count_of_pipes(str);
	param = (char **) malloc (sizeof(char *) * (count_pipe + 2));
	while (str[i] && j < (count_pipe + 1))
	{
		param[j] = get_full_str(str, &i);
		i++;
		j++;
	}
	param[j] = NULL;
	i = 0;
	j = 0;
	while (i < count_pipe + 1)
	{
	 	j = 0;
	 	while (param[i] != NULL && param[i][j] != '\0')
	 	{
			if (param[i][j] == '\\')
				param[i] = ft_slesh(param[i], &j);
			if (param[i][j] == '\\' )
				param[i] = ft_drop_slesh(param[i], &j, env);
			if (param[i][j] == '$')
				param[i] = ft_dollar(param[i], &j, env);
			if (param[i][j] == '\"')
				param[i] = d_quote(param[i], &j);
			if (param[i][j] == '\'')
				param[i] = s_quote(param[i], &j);

			printf("end_symb = %c\n", param[i][j]);
			if (param[i][j])
	 			j++;
	 	}
	 	i ++;
	}
	// i = 0;
	// while (param[i])
	// {
	// 	printf("str = %s\n", param[i]);
	// 	i++;
	// }
//	ft_parse_str(param);
}

int	ft_parser(char *str, char **env)
{
	int	i;
	int	count_pipe;

	i = 0;
	count_pipe = ft_count_of_pipes(str);
	get_list_str(str, env);
	// while (str[i])
	// {
	// 	if (str[i] == '\'')
	// 		str = s_quote(str, &i);
	// 	if (str[i] == '\\')
	// 		str = ft_slesh(str, &i);
	// 	if (str[i] == '\"')
	// 		str = d_quote(str, &i);
	// 	i++;
	// }
	// printf("\n\n\ncount pipes = %d\n", count_pipe);
	// printf("%s\n", str);
	return (0);
}
