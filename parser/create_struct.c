/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:57:07 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/21 14:57:38 by utawana          ###   ########.fr       */
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

char	**get_args(char **words, t_main *main_stuct)
{
	int		i;
	int		j;
	char	**args;

	i = -1;
	j = 0;
	args = (char **) malloc (sizeof(char *) * (count_args(words) + 1));
	if (!args)
		return (0);
	while (words[++i])
	{
		if (get_redir(words[i]) != -1)
			i++;
		else
		{
			if (ft_strncmp("$?", words[i], ft_strlen(words[i])) == 0
				&& words[i][0] != 0)
				args[j] = ft_itoa(main_stuct->status);
			else
				args[j] = ft_strdup(words[i]);
			j++;
		}
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

t_lis	*create_list(char ***blocks, int count_blocks, t_main *main_stuct)
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
		new->args = get_args(blocks[i], main_stuct);
		new->next = NULL;
		ft_lisadd_back(&list, new);
		i++;
	}
	i = 0;
	return (list);
}
