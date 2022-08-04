/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:57:07 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/03 19:48:55 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_redir(char *str)
{
	int	flag;

	flag = -1;
	if (ft_strncmp(str, ">", 2) == 0)
		return (0);
	if (ft_strncmp(str, "<", 2) == 0)
		return (1);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (3);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (4);
	return (flag);
}

int	count_args(char **words)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			i++;
		else
			count++;
		if (!words[i])
			break ;
		i++;
	}
	return (count);
}

char	**get_args(char **words)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = 0;
	args = (char **) malloc (sizeof(char *) * (count_args(words) + 1));
	if (!args)
		return (0);
	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			i++;
		else
		{
			args[j] = ft_strdup(words[i]);
			j++;
		}
		i++;
	}
	args[j] = NULL;
	return (args);
}

int	count_redir(char **words)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			count++;
		i++;
	}
	return (count);
}

t_lis	*create_list(char ***blocks, int count_blocks)
{
	int		i;
	t_lis	*list;
	t_lis	*new;

	list = NULL;
	i = 0;
	while (i < count_blocks)
	{
		new = (t_lis *) malloc(sizeof(*new));
		new->redir = NULL;
		new->redir = get_list_redir(blocks[i]);
		new->args = get_args(blocks[i]);
		new->next = NULL;
		ft_lisadd_back(&list, new);
		i++;
	}
	i = 0;
	return (list);
}
