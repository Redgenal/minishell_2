/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:57:07 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/02 18:36:57 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir(char *str)
{
	int	flag;

	flag = -1;
	if (ft_strncmp(str, ">", 2) == 0)
		return (0);
	if (ft_strncmp(str, "<", 2) == 0)
		return (1);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (3);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (4);
	printf("Here ?\n");
	return (flag);
}

int	count_args(char **words)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			i++;
		else
			count++;
		if (!words[i])
			break ;
		i++;
	}
	return (count);
}

char	**get_args(char **words)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = 0;
	args = (char **) malloc (sizeof(char *) * (count_args(words) + 1));
	if (!args)
		return (0);
	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			i++;
		else
		{
			args[j] = ft_strdup(words[i]);
			j++;
		}
		i++;
	}
	args[j] = NULL;
	return (args);
}

int	count_redir(char **words)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (words[i])
	{
		if (get_redir(words[i]) != -1)
			count++;
		i++;
	}
	return (count);
}

t_redir	*ft_redirlast(t_redir *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_rediradd_back(t_redir **lst, t_redir *new)
{
	t_redir	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_redirlast(*(lst));
			p->next = new;
		}
		else
			*lst = new;
	}
}

t_redir	*ft_redirnew(void *type, void *content)
{
	t_redir	*p;

	p = (t_redir *) malloc(sizeof(*p));
	if (!p)
		return (0);
	p->file = content;
	p->type = get_redir(type);
	p->next = NULL;
	return (p);
}

t_redir	*get_list_redir(char **envp)
{
	t_redir	*env;
	t_redir	*list;
	int		i;

	i = -1;
	env = NULL;
	while (envp[++i] != NULL)
	{
		if (get_redir(envp[i]) != -1)
		{
			list = ft_redirnew(envp[i], envp[i + 1]);
			ft_rediradd_back(&env, list);
		}
	}
	list = ft_redirnew(NULL, NULL);
	ft_rediradd_back(&env, list);
	return (env);
}

t_lis	*ft_lislast(t_lis *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}


void	ft_lisadd_back(t_lis **lst, t_lis *new)
{
	t_lis	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_lislast(*(lst));
			p->next = new;
		}
		else
			*lst = new;
	}
}

t_lis	*create_list(char ***blocks, int count_blocks)
{
	int		i;
	t_lis	*list;
	t_lis	*new;

	list = NULL;
	i = 0;
	while (i < count_blocks)
	{
		new = (t_lis *) malloc(sizeof(*new));
		new->redir = NULL;
		printf("%s\n", blocks[0][0]);
		new->redir = get_list_redir(blocks[i]);
		printf("%s\n", blocks[0][0]);
		new->args = get_args(blocks[i]);
		new->next = NULL;
		ft_lisadd_back(&list, new);
		i++;
	}
	i = 0;
	printf("%s\n", list->args[0]);
	return (list);
}

// void test_print(char ***blocks, int count_blocks)
// {
// 	t_lis	*list;
// 	int		i;
// 	int		j;


// 	j = 0;
// 	list = create_list(blocks, count_blocks);
// 	while (list)
// 	{
// 		i = 0;
// 		while ( i < 3)
// 		{
// 			printf("%s\n", list->args[i]);
// 			i++;
// 		}
// 		printf("%s\n", list->redir->file);
// 		j++;
// 		list = list->next;
// 	}
// }
