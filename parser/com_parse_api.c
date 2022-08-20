/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_parse_api.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:16:33 by utawana           #+#    #+#             */
/*   Updated: 2022/08/20 20:00:11 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_str_for_blocks(char **block)
{
	int	i;

	i = 0;
	while (block[i])
		i++;
	return (i);
}

void	blocks_free(char ***blocks, int i, int j)
{
	i--;
	while (i >= 0)
	{
		j = count_str_for_blocks(blocks[i]);
		while (j >= 0)
		{
			free(blocks[i][j]);
			j--;
		}
		free(blocks[i]);
		i--;
	}
	free(blocks);
}

int	ft_lis_check(t_lis *lis)
{
	while (lis)
	{
		if (lis->args[0][0] == 0)
			return (0);
		lis = lis->next;
	}
	return (1);
}

int	com_parser_api(char ***blocks, int count_blocks, t_main *main_stuct)
{
	t_lis	*lis;
	int		rez;

	lis = create_list(blocks, count_blocks, main_stuct);
	if (count_blocks != 0 && ft_lis_check(lis) != 0)
	{
		rez = main_exe(lis, main_stuct);
		if (rez < 0)
			rez *= -1;
		blocks_free(blocks, count_blocks, 0);
		return (rez);
	}
	else
	{
		ft_p_list_clear(lis);
		blocks_free(blocks, count_blocks, 0);
		return (0);
	}
}
