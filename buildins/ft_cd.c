/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:55:46 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:55:48 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char *str, t_list **env)
{
	char	*new_pwd;
	char	*new_opwd;
	t_list	*first;

	new_opwd = getcwd(NULL, 1000);
	if (!new_opwd)
		return (ft_ret_code(1, NULL));
	if (chdir(str))
		return (ft_ret_code(1, NULL));
	new_pwd = getcwd(NULL, 1000);
	if (!new_pwd)
		return (ft_ret_code(1, NULL));
	first = (*(env));
	while ((*env)->next)
	{
		if (ft_strncmp((*env)->content, "PWD=", 4) == 0)
			(*env)->content = ft_strjoin("PWD=", new_pwd);
		else if (ft_strncmp((*env)->content, "OLDPWD=", 7) == 0)
			(*env)->content = ft_strjoin("OLDPWD=", new_opwd);
		(*env) = (*env)->next;
	}
	free(new_opwd);
	free(new_pwd);
	(*(env)) = first;
	return (0);
}
