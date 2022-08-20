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

#include "../headers/minishell.h"

int	ft_ret_cd_code(int value, char *str)
{
	if (str && (value == 0))
		ft_putstr_fd(str, 1);
	else if (!str)
	{
		ft_putstr_fd("minishell$ cd", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": HOME not set\n", 2);
	}
	else if (str && (value == -1))
	{
		ft_putstr_fd("minishell$ cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if ((value == -1) && !str)
		perror("minishell: cd: ");
	return (value);
}

void	ft_change_dir(t_list **env, char *new_pwd, char *new_opwd)
{
	while ((*env)->next)
	{
		if (ft_strncmp((*env)->content, "PWD=", 4) == 0)
		{
			free((*env)->content);
			(*env)->content = ft_strjoin("PWD=", new_pwd);
		}
		else if (ft_strncmp((*env)->content, "OLDPWD=", 7) == 0)
		{
			free((*env)->content);
			(*env)->content = ft_strjoin("OLDPWD=", new_opwd);
		}
		(*env) = (*env)->next;
	}
}

char	*ft_find_home(t_list *env)
{
	char	*str;

	while (env != NULL)
	{
		if (ft_strncmp((env)->content, "HOME=", 5) == 0)
			break ;
		(env) = (env)->next;
	}
	if (env == NULL)
		return (NULL);
	str = ft_substr((env)->content, 5, ft_strlen((env)->content) - 5);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_change_str(char *str, t_list *env)
{
	char	*str2;

	str2 = ft_find_home(env);
	if (!str2)
	{
		return (NULL);
	}
	if (!str)
		str = str2;
	free(str2);
	return (str);
}

int	ft_cd(char *str, t_list **env)
{
	char	*new_pwd;
	char	*new_opwd;
	t_list	*first;

	new_opwd = getcwd(NULL, 1000);
	if (!new_opwd)
		return (ft_ret_cd_code(-1, NULL));
	if (chdir(ft_change_str(str, *env)))
		return (ft_ret_cd_code(-1, str));
	new_pwd = getcwd(NULL, 1000);
	if (!new_pwd)
		return (ft_ret_cd_code(-1, NULL));
	first = (*(env));
	ft_change_dir(env, new_pwd, new_opwd);
	free(new_opwd);
	free(new_pwd);
	(*env) = first;
	return (0);
}
