/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:48:07 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/14 19:37:23 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	dst_size;
	size_t	src_size;
	size_t	result;
	size_t	i;

	s = (char *)src;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(s);
	result = 0;
	if (size > dst_size)
		result = (src_size + dst_size);
	else
		result = src_size + size;
	i = 0;
	while (s[i] && (dst_size + 1) < size)
	{
		dst[dst_size] = s[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	return (result);
}
