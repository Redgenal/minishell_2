/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:53:04 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/13 13:18:33 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr (set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_check_end(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr (set, s1[len - i - 1]) == 0)
			return (len - i);
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	end;
	char	*p;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	st = ft_check_start(s1, set);
	end = ft_check_end(s1, set);
	if (st >= end)
		return (ft_strdup(""));
	p = (char *) malloc(sizeof(char) * (end - st + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, s1 + st, end - st + 1);
	return (p);
}
