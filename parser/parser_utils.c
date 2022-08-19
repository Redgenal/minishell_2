/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:57:54 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/19 18:59:54 by gantedil         ###   ########.fr       */
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
	tmp2 = ft_strjoin(tmp, tmp1);
	ft_free_two_str(tmp, tmp1);
	tmp1 = ft_strdup (str + *i + 1);
	tmp = ft_strjoin(tmp2, tmp1);
	ft_free_two_str(tmp1, tmp2);
	free (str);
	(*i)--;
	if (tmp[*i] == '\'' || tmp[*i] == '\"')
		(*i)--;
	return (tmp);
}

char	*ft_mini_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(str, 0, *i);
	tmp1 = ft_strdup (str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	++(*i);
	free(tmp1);
	free (str);
	return (tmp);
}

char	*ft_drop_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	int		j;
	int		count;

	j = *i;
	count = find_end_slesh(str, &j);
	if (str[j] == '\'' || str[j] == '\"' || str[j] == '$')
	{
		tmp = ft_substr(str, 0, *i + count / 2);
		tmp1 = ft_substr(str, j, strlen(str) - j);
		tmp2 = ft_strjoin(tmp, tmp1);
		ft_free_two_str(tmp, tmp1);
		if (tmp2 != NULL)
		{
			free (str);
			if (count % 2 == 0)
				(*i) += count / 2 - 1;
			else
				(*i) += (count / 2);
			return (tmp2);
		}
	}
	return (str);
}

int	ft_count_slesh(char *str, int i)
{
	int	j;

	j = 1;
	i--;
	while (str[i] == '\\' && i >= 0)
	{	
		j++;
		i--;
	}
	if (j % 2 == 0)
		return (0);
	return (1);
}

char	*ft_slesh(char *str, int *i, int j)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	int		count;

	count = find_end_slesh(str, &j);
	tmp = NULL;
	tmp1 = NULL;
	tmp2 = NULL;
	if (count % 2 != 0)
		count --;
	if (str[j] != '\'' && str[j] != '\"' && str[j] != '$')
	{
		tmp = ft_substr(str, 0, *i + count / 2);
		tmp1 = ft_substr(str, j, strlen(str) - j);
		tmp2 = ft_strjoin(tmp, tmp1);
		ft_free_two_str(tmp, tmp1);
	}
	if (tmp2 != NULL)
	{
		free (str);
		(*i) += count / 2 + 1;
		return (tmp2);
	}
	return (str);
}
