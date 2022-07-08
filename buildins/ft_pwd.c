#include "../minishell.h"

int	ft_pwd()
{
	char	*my_path;

	my_path = getcwd(NULL, 1000);
	free(my_path);
	return (0);
}
