/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:30:59 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/12 20:00:18 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_drop(char *p)
{
	long	i;

	i = 0;
	while (p[i] != '\0' && (p[i] == '\t' || p[i] == '\n' || p[i] == '\r'
			|| p[i] == '\v' || p[i] == '\f' || p[i] == ' '))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	char	*p;
	long	i;
	long	num;
	int		minus;

	minus = 0;
	p = (char *)str;
	i = ft_drop(p);
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			minus++;
		i++;
	}
	num = 0;
	while (p[i] && p[i] >= 48 && p[i] <= 57)
	{
		num = num * 10 + (p[i] - '0');
		i++;
	}
	if (minus == 1)
		return (-num);
	return (num);
}
