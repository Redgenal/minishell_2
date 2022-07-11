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

#include "../minishell.h"

int	ft_no_arg(t_list *env)
{
	int		i;
	char	**parse;

	i = -1;
	while (env->next)
	{
		if (env->content)
		{
			parse = ft_split(env->content, '=');
			if (!parse)
				return (ft_ret_code(1, NULL));
			printf("declare -x %s=%c%s%c\n", parse[0], '"', parse[1], '"');
			free(parse);
		}
		env = env->next;
	}
	return (0);
}

int	ft_export(t_list **env, char *str)
{
	t_list	*new;
	t_list	*first;

	first = *env;
	if (!str)
		ft_no_arg(*env);
	else
	{
		while ((*env)->next)
			(*env) = (*env)->next;
		(*(env))->content = str;
		new = ft_lstnew(NULL);
		ft_lstadd_back(env, new);
	}
	*env = first;
	return (0);
}
