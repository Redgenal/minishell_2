/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:49:28 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/11 15:17:07 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (0);
	p = ft_strdup(s);
	if (!p)
		return (0);
	while (p[i])
	{
		p[i] = f(i, p[i]);
		i++;
	}
	return (p);
}
