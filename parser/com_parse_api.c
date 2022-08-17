/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_parse_api.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:16:33 by utawana           #+#    #+#             */
/*   Updated: 2022/08/17 20:04:26 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	blocks_free(char ***blocks, int i, int j)
{
	i--;
	j--;
	while (i >= 0)
	{
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

int	com_parser_api(char ***blocks, int count_blocks, t_main *main_stuct)
{
	t_lis	*lis;
	int		rez;

	lis = create_list(blocks, count_blocks);
	if (count_blocks != 0)
	{
		rez = main_exe(lis, main_stuct);
		if (rez < 0)
			rez *= -1;
		return (rez);
	}
	else
		return (0);
}
