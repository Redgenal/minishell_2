/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:59:02 by gantedil          #+#    #+#             */
/*   Updated: 2021/10/11 18:47:18 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_order(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{	
		i++;
		n *= (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	p;

	p = ft_order(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	num = (char *) malloc (sizeof(char) * (p + 1));
	if (!num)
		return (0);
	if (n < 0)
	{
		num[0] = '-';
		n = n * (-1);
	}
	num[p--] = '\0';
	while (n / 10)
	{
		num[p] = n % 10 + '0';
		n = n / 10;
		p--;
	}
	num[p] = n % 10 + '0';
	return (num);
}
