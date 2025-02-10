/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:02:24 by vcarrara          #+#    #+#             */
/*   Updated: 2023/10/26 15:26:05 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		count;
	t_list	*last;

	count = 1;
	last = lst;
	if (!lst)
		return (0);
	while (last->next != NULL)
	{
		count++;
		last = last->next;
	}
	return (last);
}

void	ft_lstadd_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}

int	search_nl(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

int	len_to_nl(t_list *list)
{
	int	len;
	int	i;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	buf_to_line(t_list *list, char *line)
{
	int	i;
	int	j;

	if (!list)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
			{
				line[i++] = '\n';
				line[i] = '\0';
				return ;
			}
			line[i++] = list->content[j++];
		}
		list = list->next;
	}
	line[i] = '\0';
}
