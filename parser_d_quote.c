/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_d_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:56:26 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/24 18:39:01 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_d_drop_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;
	int		j;
	int		count;

	j = *i;
	count = 0;
	tmp = NULL;
	tmp1 = NULL;
	while (str[j] == '\\')
	{
		count++;
		j++;
	}
	if (str[j] == '\"' || str[j] == '$')
	{
		tmp = ft_substr(str, 0, *i + count / 2);
		tmp1 = ft_substr(str, j, strlen(str) - j);
		tmp = ft_strjoin(tmp, tmp1);
		free (tmp1);
		if (tmp != NULL)
		{
			free (str);
			if (count % 2 == 0)
				(*i) += count / 2;
			else
				(*i) += (count / 2) + 1;
			return (tmp);
		}
	}
	return (str);
}

char	*ft_d_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;
	int		j;
	int		count;

	j = *i;
	count = 0;
	tmp = NULL;
	tmp1 = NULL;
	while (str[j] == '\\')
	{
		count++;
		j++;
	}
	if (count % 2 != 0)
		count ++;
	if (str[j] != '\"' && str[j] != '$')
	{
		tmp = ft_substr(str, 0, *i + count / 2);
		tmp1 = ft_substr(str, j, strlen(str) - j);
		tmp = ft_strjoin(tmp, tmp1);
		free (tmp1);
	}
	if (tmp != NULL)
	{
		free (str);
		(*i) += count / 2 + 1;
		return (tmp);
	}
	return (str);
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
		if (str[*i] == '\\')
			str = ft_d_slesh(str, i);
		if (str[*i] == '\\' )
			str = ft_d_drop_slesh(str, i);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
//	printf("TMP = %s\n", tmp);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup (str + *i + 1);
//    printf("TMP1 = %s\n", tmp1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	(*i) -= 2;
	free(tmp1);
	free(tmp2);
	free(str);
	return (tmp);
}


