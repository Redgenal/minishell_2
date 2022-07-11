/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:04:40 by utawana           #+#    #+#             */
/*   Updated: 2022/05/19 20:04:42 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*env;
	t_list	*list;
	int		i;

	i = 0;
	env = NULL;
	(void) argv;
	(void) argc;
	while (envp[i])
		i++;
	i = -1;
	while (envp[++i] != NULL)
	{
		list = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, list);
	}
	list = ft_lstnew(NULL);
	// ft_lstadd_back(&env, list);
	// ft_env(env);
	// ft_export(&env, NULL);
	// ft_pwd();
	// ft_cd("/Users/utawana", &env);
	// ft_env(env);
	printf("%d\n", ft_exit(argv[1], argv));
	return (0);
}
