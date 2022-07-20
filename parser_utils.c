/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 04:57:54 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/20 21:03:44 by gantedil         ###   ########.fr       */
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

char	*ft_parse_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;
	int		count;
	int		j;

	tmp = ft_substr(str, 0, *i);
	j = *i;
	count = 0;
	while (str[j] && str[j] == '\\')
	{
		count++;
		j++;
	}
	if (count % 2 != 0)
		count++;
	tmp1 = ft_substr(str, *i + count/2, strlen(str) - *i - 1);
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
		count--;
	if (str[j] == '\'' || str[j] == '\"')
	{
		tmp = ft_substr(str, 0, *i + count / 2);
		printf("tmp = %s\n", tmp);
		tmp1 = ft_substr(str, j, strlen(str) - j);
		tmp = ft_strjoin(tmp, tmp1);
		free (tmp1);
	}
	if (tmp != NULL)
	{
		free (str);
		(*i) += count / 2;
		printf("\nstr = %c\n", tmp[*i]);
		return (tmp);
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

char	*ft_slesh(char *str, int *i)
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
		count --;
	if (str[j] != '\'' && str[j] != '\"')
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