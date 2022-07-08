/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:13:28 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/13 15:09:36 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free (strings);
	return (0);
}

static size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!s[i])
		return (i);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count ++;
			while (s[i] && s[i] == c)
				i++;
			i--;
		}
		i++;
	}
	if (s[i - 1] != c)
		count ++;
	return (count);
}

static char	*get_str(char *p, char c, size_t last_len)
{
	p += last_len;
	while (*p && *p == c)
		p++;
	return (p);
}

static size_t	get_len(char *p, char c)
{
	size_t	i;

	i = 0;
	while (*p && (*p != c))
	{
		p ++;
		i ++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	char			*str;
	size_t			i;
	size_t			str_len;

	if (!s)
		return (0);
	strings = (char **) malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!strings)
		return (0);
	i = 0;
	str = (char *) s;
	str_len = 0;
	while (i < words_count(s, c))
	{
		str = get_str(str, c, str_len);
		str_len = get_len(str, c);
		strings[i] = (char *) malloc(sizeof(char) * (str_len + 1));
		if (!strings[i])
			return (ft_error(strings));
		ft_strlcpy(strings[i], str, str_len + 1);
		i++;
	}
	strings[i] = 0;
	return (strings);
}
