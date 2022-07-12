/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:00:24 by utawana           #+#    #+#             */
/*   Updated: 2022/02/04 16:00:26 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_call_exit(void)
{
	perror("Eror");
	exit(1);
}

void	ft_call_com_not_found(void)
{
	perror("command not found");
	exit(127);
}

void	ft_call_cant_open(void)
{
	perror("Can not open");
	exit(0);
}

void	ft_call_cant_exe(void)
{
	perror("Command invoked cannot execute");
	exit(127);
}
