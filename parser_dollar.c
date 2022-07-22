/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:59:21 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/22 16:43:30 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*ft_dollar(char *str, int *i, char **env)
{
	char	*tmp;
	char	*tmp1;
	int		j;
	int		z;
	int		k;

	j = *i;
	z = 0;
	while (str[++(*i)])
		if (!if_key(str[*i]))
			break ;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	printf ("TMP_$ = %s\n", tmp);
	k = 0;
	while (env[k] != NULL)
	{
		if (strstr(env[k], tmp))
		{
			z = 0;
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp1 = ft_substr(env[k], 0, z);
			if (strcmp(tmp, tmp1) == 0)
				break ;
		}
		k++;
	}
	tmp1 = ft_substr(env[k], z + 1, strlen(env[k]) - z);
	printf ("TMP1_$ = %s\n", tmp1);
	return (tmp1);
}
