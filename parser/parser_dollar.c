/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:59:21 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/19 19:25:39 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ft_get_env_name(char *str, int *i)
{
	int		j;
	char	*tmp;

	j = *i;
	while (str[++(*i)])
		if (!if_key(str[*i]))
			break ;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	return (tmp);
}

char	*ft_get_dollar_end(int *flag, char *env_k, char *tmp, int z)
{
	char	*tmp1;

	tmp1 = NULL;
	if (ft_strncmp("$?", tmp, ft_strlen(tmp)) == 0)
		return (tmp);
	if (env_k)
	{
		tmp1 = ft_substr(env_k, z + 1, strlen(env_k) - z);
		*flag = 1;
	}
	if (!tmp1)
	{
		*flag = 0;
		return (tmp);
	}
	free(tmp);
	return (tmp1);
}

char	*ft_get_dollar(char *str, int *i, char **env, int *flag)
{
	char	*tmp;
	char	*tmp1;
	int		z;
	int		k;

	z = 0;
	tmp = ft_get_env_name(str, i);
	tmp1 = NULL;
	k = -1;
	while (env[++k] != NULL)
	{
		if (strstr(env[k], tmp))
		{
			z = 0;
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp1 = ft_substr(env[k], 0, z);
			if (!tmp1 || (strcmp(tmp, tmp1) == 0))
				break ;
		}
	}
	if (tmp1)
		free(tmp1);
	return (ft_get_dollar_end(flag, env[k], tmp, z));
}

char	*ft_dollar(char *str, int *i, char **env)
{
	int		j;
	int		flag;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	flag = 0;
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_get_dollar(str, &j, env, &flag);
	tmp2 = ft_strdup(str + *i + ft_strlen(ft_get_env_name(str, i)) + 1);
	if (flag == 1)
		tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	free (tmp1);
	free (tmp2);
	free (str);
	return (tmp);
}
