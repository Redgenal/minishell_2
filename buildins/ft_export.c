#include "../minishell.h"

int	ft_no_arg(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (env[i])
			printf("declare -x %s\n", env[i]);
	return (0);
}

int ft_export(char **env, char *str)
{
	int	i;

	i = -1;
	if (!str)
		ft_no_arg(env);
	else
	{
		i++;
		while (env[i])
			i++;
		env[i] = str;
		env[++i] = NULL;
	}
	return (0);
}
