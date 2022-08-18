/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:26:48 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/18 22:22:28 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_some_var(char *str, int *i, char **env)
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
	if (ft_strncmp("$?", tmp1, ft_strlen(tmp1)) == 0)
		return (tmp1);
	tmp2 = ft_strdup(str + *i + ft_strlen(ft_get_env_name(str, i)) + 1);
	if (flag == 1)
		tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	(*i)--;
	free (tmp1);
	free (tmp2);
	return (tmp);
}

char	*ft_split_dollar(char *str, int *i, char **env)
{
	int		j;
	char	*tmp;
	char	**tmp3;

	tmp = create_some_var(str, i, env);
	tmp3 = ft_split(tmp, ' ');
	tmp = ft_substr(str, 0, 0);
	j = 0;
	while (tmp3[j])
	{
		tmp = ft_strjoin(tmp, tmp3[j]);
		if (j > 0 && tmp3[j + 1])
			tmp = ft_strjoin(tmp, " ");
		j++;
	}
	while (j >= 0)
	{
		free(tmp3[j]);
		j--;
	}
	free(tmp3);
	return (tmp);
}
