/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_d_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:56:26 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/03 15:22:26 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_end_slesh(char *str, int *j)
{
	int	count;

	count = 0;
	while (str[*j] == '\\')
	{
		count++;
		(*j)++;
	}
	return (count);
}

char	*ft_d_drop_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;
	int		j;
	int		count;

	j = *i;
	count = find_end_slesh(str, &j);
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
	count = find_end_slesh(str, &j);
	tmp = NULL;
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

char	*check_special_val(char *str, int *i, char **env)
{
	int	len;

	if (str[*i] == '\\')
		str = ft_d_slesh(str, i);
	if (str[*i] == '\\' )
		str = ft_d_drop_slesh(str, i);
	if (str[*i] == '$' )
	{
		len = ft_strlen(str);
		str = ft_dollar(str, i, env);
		*i += ft_strlen(str) - len;
	}
	return (str);
}

char	*d_quote(char *str, int *i, char **env)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	while (str[(*i)++])
	{
		str = check_special_val(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup (str + *i + 1);
	tmp1 = ft_strjoin(tmp, tmp1);
	tmp2 = ft_strjoin(tmp1, tmp2);
	free(tmp);
	free(tmp1);
	free(str);
	(*i)--;
	if (tmp2[*i] == '\"')
		(*i)--;
	return (tmp2);
}
