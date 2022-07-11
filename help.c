/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:08:41 by utawana           #+#    #+#             */
/*   Updated: 2022/07/11 16:08:43 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ret_code(int value, char *str)
{
	if (str && (value == 0))
		ft_putstr_fd(str, 1);
	else if (str && (value == 1))
		perror(str);
	else if ((value == 1) && !str)
		perror("Minishell error:");
	return (value);
}
