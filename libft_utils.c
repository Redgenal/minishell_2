/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:06:45 by gantedil          #+#    #+#             */
/*   Updated: 2022/07/05 17:11:13 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *) s;
	i = 0;
	while (p[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	size_t			size;

	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = (char *) malloc (sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	i = start;
	size = 0;
	while (s[i] && (size < len))
	{
		p[size] = s[i];
		size++;
		i++;
	}
	p[size] = '\0';
	return (p);
}

char	*ft_strdup(const char *str)
{
	char		*p;
	size_t		len;
	size_t		i;

	len = ft_strlen(str);
	i = 0;
	p = (char *) malloc(sizeof(*p) * (len + 1));
	if (!p)
		return (0);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	size_t			i;
	size_t			k;
	int				size;

	if (!s1)
		return (0);
	size = ft_strlen ((char *)s1) + ft_strlen ((char *)s2);
	p = (char *) malloc(sizeof(*p) * size);
	i = 0;
	k = 0;
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		p[i++] = s2[k++];
	}
	p[i] = '\0';
	return (p);
}
