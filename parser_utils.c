/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:57:54 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/19 06:24:27 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*s_quote(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	tmp = ft_substr(str, 0, j);
	while (str[(*i)++])
	{
		if (str[*i] == '\'')
			break ;
	}
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup (str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	return (tmp);
}

char	*ft_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(str, 0, *i);
	tmp1 = ft_substr(str, *i + 1, strlen(str) - *i - 1);
	tmp = ft_strjoin(tmp, tmp1);
	free(tmp1);
	free(str);
	(*i)++;
	return (tmp);
}

char	*d_quote(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	while (str[(*i)++])
	{
		if (str[*i] == '\\' && (str[(*i + 1)] == '\"' \
			|| str[(*i + 1)] == '$' || str[(*i + 1)] == '\\'))
			str = ft_slesh(str, i);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	return (tmp);
}

char	*ft_drop_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(str, 0, *i);
	tmp1 = ft_substr(str, *i + 1, strlen(str) - *i - 1);
	tmp = ft_strjoin(tmp, tmp1);
	free(tmp1);
	free(str);
	(*i)++;
	return (tmp);
}