#include "minishell.h"

int	ft_ret_code(int value, char *str)
{
	if (str)
	{
		if (value == 0)
			ft_putstr(str, STD_OUT);
		else
			ft_putstr(str, STD_ERR);
	}
	return (value);
}