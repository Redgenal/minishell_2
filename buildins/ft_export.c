/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:56:16 by utawana           #+#    #+#             */
/*   Updated: 2022/07/08 18:56:18 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_ret_code(int value, char *str)
{
	if (str && (value == 0))
		ft_putstr_fd(str, 1);
	else if (str && (value == -1))
	{
		ft_putstr_fd("minishell$ export: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if ((value == -1) && !str)
		perror("minishell$ cd: ");
	return (value);
}

int	ft_no_arg(t_list *env)
{
	char	**parse;
	int		i;

	i = 0;
	while (env)
	{
		if (env->content)
		{
			parse = ft_split(env->content, '=');
			if (!parse)
				return (ft_ret_code(-1, NULL));
			printf("declare -x %s=%c%s%c\n", parse[0], '"', parse[1], '"');
			ft_free_split(parse);
		}
		i++;
		env = env->next;
	}
	return (0);
}

int	ft_strncmp_ust(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		if (!*(unsigned char *)(s1 + i) || !*(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	if (s2[i] == '=')
		return (777);
	return (0);
}

void	ft_circle_func(t_list **env, char **str, t_list *first)
{
	int		i;
	t_list	*new;
	char	**split;

	i = 0;
	while (str[++i])
	{
		while ((*env))
		{
			split = ft_split(str[i], '=');
			ft_help_export(split, env, str[i], first);
			ft_free_split(split);
			if ((*env)->next)
				(*env) = (*env)->next;
			else
				break ;
		}
		new = ft_lstnew(str[i]);
		ft_lstadd_back(env, new);
		*env = first;
	}
}

int	ft_export(t_list **env, char **str)
{
	t_list	*first;
	int		i;

	first = *env;
	if (str[1] == NULL)
		ft_no_arg(*env);
	else
	{
		i = 0;
		while (str[++i])
		{
			if (ft_isdigit(str[i][0]))
			{
				ft_putstr_fd("minishell$ export: ", 2);
				ft_putstr_fd(str[i], 2);
				ft_putstr_fd(": not a valid identifier\n", 2);
				return (-1);
			}
		}
		ft_circle_func(env, str, first);
	}
	*env = first;
	return (0);
}
