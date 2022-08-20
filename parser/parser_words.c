/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:51:25 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/20 19:29:41 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_count_words_loop(char *str, int *i, int *count)
{
	if (str[*i] == '\"' && ft_count_slesh(str, *i))
	{
		(*i)++;
		*i = count_d_quote(str, *i);
	}
	if (str[*i] == '\'' && ft_count_slesh(str, *i))
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
	}
	if (str[*i] == '>' || str[*i] == '<')
	{
		(*count)++;
		if (str[*i + 1] == '>' || str[*i + 1] == '<')
			(*i)++;
		if (str[*i + 1] != '\0' && str[*i + 1] != ' ' && str[*i + 1] != '\t')
			(*count)++;
	}
	if ((str[*i] == ' ' || str[*i] == '\t') && str[*i + 1] != ' ' \
		&& str[*i + 1] != '\0' && str[*i + 1] != '>' && str[*i + 1] != '<')
		(*count)++;
}

int	get_count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] != '<' && str[i] != '>')
		count++;
	while (str[i])
	{
		get_count_words_loop(str, &i, &count);
		i++;
	}
	return (count);
}

char	*parse_word(char *param, char **env)
{
	int	j;

	j = 0;
	while (param[j] != '\0')
	{
		if (param[j] == '\"')
			param = d_quote(param, &j, env, 0);
		if (param[j] == '\'')
			param = s_quote(param, &j);
		if (param[j] == '$')
		{
			param = ft_split_dollar(param, &j, env);
			j++;
			continue ;
		}
		if (param[j] == '\\')
			param = ft_slesh(param, &j, j);
		if (param[j] == '\\' )
			param = ft_drop_slesh(param, &j);
		if (param[j])
			j++;
	}
	return (param);
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
}

char	*ft_dollar_two(int flag, char *tmp, char *tmp1, char *tmp2)
{
	char	*tmp3;

	tmp3 = NULL;
	if (flag == 1)
	{
		tmp3 = ft_strjoin(tmp, tmp1);
		ft_free_two_str(tmp, tmp1);
		tmp = ft_strjoin(tmp3, tmp2);
		ft_free_two_str(tmp2, tmp3);
		if (tmp == NULL)
			tmp = ft_strdup("");
		return (tmp);
	}
	else
	{
		tmp3 = ft_strjoin(tmp, tmp2);
		free(tmp1);
		ft_free_two_str(tmp, tmp2);
		return (tmp3);
	}
}
