/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:44:38 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/13 15:10:46 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	size_t			i;
	size_t			k;
	int				size;

	if (!s1)
		return (0);
	size = ft_strlen ((char *)s1) + ft_strlen ((char *)s2);
	p = (char *) malloc(sizeof(*p) * (size + 1));
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
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}
