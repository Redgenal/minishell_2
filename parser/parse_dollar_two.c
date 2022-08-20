/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <utawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:26:48 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/20 17:28:14 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_some_var_two(char *tmp, char *tmp1, int flag, char *tmp3)
{
	char	*tmp2;

	if (flag == 1)
	{
		tmp2 = ft_strjoin(tmp, tmp1);
		ft_free_two_str(tmp, tmp1);
		tmp = ft_strjoin(tmp2, tmp3);
		ft_free_two_str(tmp2, tmp3);
		if (tmp == NULL)
			tmp = ft_strdup("");
		return (tmp);
	}
	else
	{
		tmp2 = ft_strjoin(tmp, tmp3);
		free(tmp1);
		ft_free_two_str(tmp, tmp3);
		return (tmp2);
	}
}

char	*create_some_var(char *str, int *i, char **env, int j)
{
	int		flag;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	flag = 0;
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_get_dollar(str, &j, env, &flag);
	j = *i;
	tmp2 = ft_get_env_name(str, i);
	tmp3 = ft_strdup(str + j + ft_strlen(tmp2) + 1);
	free (tmp2);
	(*i)--;
	return (create_some_var_two(tmp, tmp1, flag, tmp3));
}

char	*ft_split_dollar_two(char *tmp, char **tmp3, char *str, char *tmp1)
{
	int	j;

	j = 0;
	while (tmp3[j])
		j++;
	if (tmp1 == NULL)
	{
		if (*str)
			free(str);
		while (j >= 0)
		{
			free(tmp3[j]);
			j--;
		}
		free(tmp3);
		return (tmp);
	}
	free(tmp);
	while (--j >= 0)
		free(tmp3[j]);
	free(tmp3);
	free(str);
	return (tmp1);
}

char	*ft_split_dollar(char *str, int *i, char **env)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	**tmp3;

	if (ft_strncmp(str, "$?", ft_strlen(str)) == 0)
		return (str);
	tmp = create_some_var(str, i, env, 0);
	tmp1 = NULL;
	tmp3 = ft_split(tmp, ' ');
	free (tmp);
	tmp = ft_strdup("");
	j = 0;
	while (tmp3[j])
	{
		tmp1 = ft_strjoin(tmp, tmp3[j]);
		free(tmp);
		if (j > 0 && tmp3[j + 1])
			tmp = ft_strjoin(tmp1, " ");
		else
			tmp = ft_strdup(tmp1);
		j++;
	}
	return (ft_split_dollar_two(tmp, tmp3, str, tmp1));
}

void	ft_free_two_str(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
