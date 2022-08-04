/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:12:56 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/04 17:26:56 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_list_words_loop_one(char *str, t_words *w)
{
	while (str[w->i] && (str[w->i] == ' ' || str[w->i] == '\t'))
	{
		if (w->i > 0 && (str[w->i - 1] != ' ' && str[w->i - 1] != '\t'))
			break ;
		w->start = ++(w->i);
	}
	if (str[w->i] == '<' || str[w->i] == '>')
	{
		if ((w->i > 0) && (str[w->i - 1] != ' ' && str[w->i - 1] != '\t'))
		{
			w->result[(w->j)++] = ft_substr(str, w->start, w->i - w->start);
			w->start = w->i;
		}
		if (str[w->i + 1] == '<' || str[w->i + 1] == '>')
		{
			w->result[(w->j)++] = ft_substr(str, w->start, 2);
			w->i++;
		}
		else
			w->result[(w->j)++] = ft_substr(str, w->start, 1);
		w->i++;
		w->start = w->i;
	}
}

void	get_list_words_loop_two(char *str, t_words *w)
{
	if (str[w->i] == '\"' && ft_count_slesh(str, w->i))
	{
		(w->i)++;
		w->i = count_d_quote(str, w->i);
	}
	if (str[w->i] == '\'' && ft_count_slesh(str, w->i))
	{
		(w->i)++;
		while (str[w->i] && str[w->i] != '\'')
			(w->i)++;
	}
	if ((str[w->i] == ' ' || str[w->i] == '\t') && (w->i > 0) && \
		str[w->i - 1] != '<' && str[w->i - 1] != '>')
	{
		w->result[(w->j)++] = ft_substr(str, w->start, w->i - w->start);
		w->start = w->i + 1;
	}
	if ((str[w->i] == ' ' || str[w->i] == '\t') && (w->i > 0) \
		&& (str[w->i - 1] == '<' || str[w->i - 1] == '>'))
		w->start++;
	if (str[w->i + 1] == '\0' && str[w->i] != ' ' && str[w->i] != '\t')
		w->result[w->j] = ft_substr(str, w->start, w->i - w->start + 1);
}

void	start_word(char *str, t_words *words)
{
	int	k;
	int	i;

	k = strlen(str);
	while (k > 0)
	{
		k--;
		if (str[k] != ' ' && str[k] != '\t')
			break ;
		str[k] = '\0';
	}
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	words->i = i;
	words->start = i;
}

void	init_struct_word(t_words *words)
{
	words->i = 0;
	words->j = 0;
	words->start = 0;
	words->result = NULL;
}

char	**get_list_words(char *str)
{
	t_words	*words;
	char	**result;

	if (!str)
		return (0);
	result = (char **) malloc(sizeof(char *) * (get_count_words(str) + 1));
	if (!result)
		return (0);
	words = (t_words *) malloc (sizeof(*words));
	init_struct_word(words);
	start_word(str, words);
	words->result = result;
	while (str[words->i] != '\0')
	{
		get_list_words_loop_one(str, words);
		get_list_words_loop_two(str, words);
		(words->i)++;
	}
	words->j++;
	words->result[words->j] = NULL;
	free (str);
	result = words->result;
	free (words);
	return (result);
}