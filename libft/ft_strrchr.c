/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:52:11 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/13 15:22:46 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;
	int		last;

	p = (char *) s;
	i = 0;
	last = -1;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			last = i;
		i++;
	}
	if (last > -1)
		return (&p[last]);
	if (p[i] == (unsigned char)c)
		return (&p[i]);
	return (0);
}	
