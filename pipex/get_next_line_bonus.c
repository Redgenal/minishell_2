/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utawana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:17:54 by utawana           #+#    #+#             */
/*   Updated: 2021/10/20 15:28:31 by utawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_newost(char *ost)
{
	ost = malloc(sizeof(char));
	if (!ost)
		return ((void *) 0);
	*ost = '\0';
	return (ost);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*mem;
	int		len;
	int		i;

	len = ft_strlen_gnl(s1);
	i = 0;
	mem = malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	while (i < len)
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i - 1] = '\0';
	return (mem);
}

char	*get_result(char *ost, int rd)
{
	char	*result;

	if (rd > 0)
		result = ft_substr_gnl(ost, 0, (ft_strchr_gnl(ost, '\n')) - ost + 1);
	else if (rd == -1 || (rd == 0 && *ost == '\0'))
	{
		free(ost);
		return (NULL);
	}
	else
		result = ft_strdup_gnl(ost);
	return (result);
}

int	ft_newrd(char **ost, int rd, char *buff, int fd)
{
	char		*tmp;

	buff[rd] = '\0';
	tmp = ft_strjoin_gnl(*ost, buff);
	free(*ost);
	*ost = tmp;
	if (!ft_strchr_gnl(*ost, '\n'))
		rd = read(fd, buff, BUFFER_SIZE);
	return (rd);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*ost;
	int			rd;
	char		*result;
	char		*tmp;

	if (ost == 0)
		ost = ft_newost(ost);
	rd = 1;
	if (!ft_strchr_gnl(ost, '\n'))
		rd = read(fd, buff, BUFFER_SIZE);
	while (!(ft_strchr_gnl(ost, '\n')) && (rd) > 0)
		rd = ft_newrd(&ost, rd, buff, fd);
	result = get_result(ost, rd);
	if (!result)
	{
		ost = NULL;
		return (NULL);
	}	
	tmp = ft_strdup_gnl(ost + (ft_strlen_gnl(result)));
	free(ost);
	ost = tmp;
	return (result);
}
