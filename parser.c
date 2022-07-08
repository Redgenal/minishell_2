/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:29:59 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/05 20:56:28 by gantedil         ###   ########.fr       */
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
	free(str);
	return (tmp);
}

char	*ft_slesh(char *str, int *i)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(str, 0, *i);
	tmp1 = ft_strdup (str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	++(*i);
	free (str);
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
		if (str[*i] == '\\' && (str[(*i + 1)] == '\"' || str[(*i + 1)] == '$' || str[(*i + 1)] == '\\'))
			str = ft_slesh(str, i);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	free (str);
	return (tmp);
}

int	ft_parser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = s_quote(str, &i);
		if (str[i] == '\\')
			str = ft_slesh(str, &i);
		if (str[i] == '\"')
			str = d_quote(str, &i);
		i++;
	}
		printf("%s\n", str);
	return (0);
}

// int	main(int argc, char **argv, char **env)
// {
// 	char *str = ft_strdup("\"$PATH\"");
// 	ft_parser(str);
// 	return (0);
// }
