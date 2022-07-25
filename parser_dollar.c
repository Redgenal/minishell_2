/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:59:21 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/25 19:51:15 by gantedil         ###   ########.fr       */
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

char	*ft_get_dollar(char *str, int *i, char **env, int *flag)
{
	char	*tmp;
	char	*tmp1;
	int		j;
	int		z;
	int		k;

	j = *i;
	z = 0;
	tmp1 = NULL;
	while (str[++(*i)])
		if (!if_key(str[*i]))
			break ;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
//	printf ("TMP_$ = %s\n", tmp);
	k = 0;
	while (env[k] != NULL)
	{
		if (strstr(env[k], tmp))
		{
			z = 0;
			while (env[k][z] && env[k][z] != '=')
				z++;
			tmp1 = ft_substr(env[k], 0, z);
			if (!tmp1)
				break ;
			if (strcmp(tmp, tmp1) == 0)
				break ;
		}
		k++;
	}
	if (env[k] != NULL)
	{
		tmp1 = ft_substr(env[k], z + 1, strlen(env[k]) - z);
		*flag = 1;
	}
//	printf ("TMP1_$ = %s\n", tmp1);
	if (!tmp1)
	{
		*flag = 0;
		free(tmp1);
		return (tmp);
	}
	free(tmp);
	return (tmp1);
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
//	printf("TMP! = %s\n", tmp);
	tmp1 = ft_get_dollar(str, &j, env, &flag);
//	printf("TMP_1! = %s\n", tmp1);
	tmp2 = ft_strdup(str + *i + ft_strlen(ft_get_env_name(str, i)) + 1);
//	printf("TMP_2! = %s\n", tmp2);
	if (flag == 1)
		tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
//	printf("TMP_final! = %s\n", tmp);
//	printf("TMP_final_char! = %c\n", tmp[*i]);
	free (tmp1);
	free (tmp2);
	free (str);
	return (tmp);
}

char	*ft_split_dollar(char *str, int *i, char **env)
{
	int		j;
	int		flag;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	char	**tmp3;

	j = *i;
	flag = 0;
	tmp = ft_substr(str, 0, j);
//	printf("TMP! = %s\n", tmp);
	tmp1 = ft_get_dollar(str, &j, env, &flag);
//	printf("TMP_1! = %s\n", tmp1);
	tmp2 = ft_strdup(str + *i + ft_strlen(ft_get_env_name(str, i)) + 1);
//	printf("TMP_2! = %s\n", tmp2);
	if (flag == 1)
		tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
//	printf("TMP_final! = %s\n", tmp);
//	printf("TMP_final_char! = %c\n", tmp[*i]);
	printf("!!!!\n");
	tmp3 = ft_split(tmp, ' ');
	tmp = ft_substr(str, 0, 0);
	j = 0;
	while (tmp3[j])
	{
		tmp = ft_strjoin(tmp, tmp3[j]);
		tmp = ft_strjoin(tmp, " ");
		j++;
	}
	while (j >= 0)
	{
		free(tmp3[j]);
		j--;
	}
	free (tmp1);
	free (tmp2);
	free(tmp3);
	free (str);
	return (tmp);
}
