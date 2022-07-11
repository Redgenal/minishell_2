/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:29 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:30 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(void)
{
	char	*my_path;

	my_path = getcwd(NULL, 1000);
	if (!my_path)
		return (ft_ret_code(1, NULL));
	printf("\n%s\n\n", my_path);
	free(my_path);
	return (0);
}
