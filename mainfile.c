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
	char	**my_envp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	printf("i = %d\n", i);
	my_envp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i] != NULL)
	{
		my_envp[i] = malloc(sizeof(char) * ft_strlen(envp[i]) + 1);
		ft_strlcpy(my_envp[i], envp[i], ft_strlen(envp[i]) + 1);
		printf("%s\n", my_envp[i]);
	}
	my_envp[i] = NULL;
	if (argc == 2)
		printf("%s, %s" ,argv[0], envp[0]);
	ft_env(my_envp);
	ft_pwd();
	ft_cd("/Users/utawana", my_envp);
	ft_pwd();
	ft_env(my_envp);
	return (0);
}
