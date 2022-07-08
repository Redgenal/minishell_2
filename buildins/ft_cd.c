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

int	ft_cd(char *str, char **env)
{
	char	*new_pwd;
	char	*new_opwd;
	int		i;

	new_opwd = getcwd(NULL, 1000);
	if (chdir(str))
	{
		perror("Minishell error");
	}
	new_pwd = getcwd(NULL, 1000);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			free(env[i]);
			printf("\nnew_pwd = %s\n\n", new_pwd);
			env[i] = ft_strjoin("PWD=", new_pwd);
			printf("\n%s\n\n", env[i]);
		}
		else if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			free(env[i]);
			printf("\nnew_opwd = %s\n\n", new_pwd);
			env[i] = ft_strjoin("OLDPWD=", new_opwd);
			printf("\n%s\n\n", env[i]);
		}
	}
	free(new_opwd);
	free(new_pwd);
	return (0);
}
