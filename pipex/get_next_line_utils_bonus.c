/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:18:50 by utawana           #+#    #+#             */
/*   Updated: 2021/10/14 12:18:53 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *string, int symbol)
{
	int				i;
	unsigned char	*result;

	i = 0;
	while ((unsigned char)string[i] != (unsigned char)symbol)
	{
		if (string[i] == '\0')
			return (0);
		i++;
	}
	result = (unsigned char *) &string[i];
	return ((char *)(result));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		k;
	int		n;
	char	*str;

	if (!s1)
		return (NULL);
	k = 0;
	n = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	while (s2[n])
	{
		str[k] = s2[n];
		k++;
		n++;
	}
	str[k] = '\0';
	return (str);
}

static size_t	ft_min_gnl(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	lenght;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen_gnl(s);
	s2 = malloc(sizeof(char) * (ft_min_gnl(len, lenght) + 1));
	if (!s2)
		return (NULL);
	s2[i] = '\0';
	if (start >= lenght)
		return (s2);
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i - 1] = '\0';
	return (s2);
}
