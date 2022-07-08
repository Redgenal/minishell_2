#include "../minishell.h"

int	ft_cd(char *str)
{
	if (chdir(str))
	{
		perror("Minishell error");
	}
	return (0);
}
