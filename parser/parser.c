/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:29:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/17 20:02:26 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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

void	set_blocks(int count_param, char ***blocks, char **pipes, t_main *main)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count_param)
	{
		j = 0;
		blocks[i] = get_list_words(pipes[i]);
		while (blocks[i][j])
		{
			blocks[i][j] = parse_word(blocks[i][j], main->my_env);
			j++;
		}
	}
	blocks[i] = NULL;
}

int	ft_parser(char *str, t_main *main_struct)
{
	int		i;
	char	**pipes_strs;
	char	***blocks;

	pipes_strs = get_list_str(str);
	i = 0;
	while (pipes_strs[i])
		i++;
	blocks = (char ***) malloc(sizeof(char **) * (i + 1));
	if (!blocks)
		return (0);
	set_blocks(i, blocks, pipes_strs, main_struct);
	return (com_parser_api(blocks, i, main_struct));
}
