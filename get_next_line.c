/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:57:09 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/14 16:37:50 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd);
char	*catch_line(t_list *list);
void	organize(t_list **list);
void	free_list(t_list **list, t_list *clean, char *buf);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = catch_line(list);
	organize(&list);
	return (next_line);
}

void	create_list(t_list **list, int fd)
{
	int		c_read;
	char	*buf;

	while (!search_nl(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		c_read = read(fd, buf, BUFFER_SIZE);
		if (!c_read)
		{
			free(buf);
			return ;
		}
		buf[c_read] = '\0';
		ft_lstadd_back(list, buf);
	}
}

char	*catch_line(t_list *list)
{
	int		line_len;
	char	*next_line;

	if (!list)
		return (NULL);
	line_len = len_to_nl(list);
	next_line = malloc(line_len + 1);
	buf_to_line(list, next_line);
	return (next_line);
}

void	organize(t_list **list)
{
	char	*buf;
	int		i;
	int		j;
	t_list	*last;
	t_list	*clean;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if ((!buf) || (!clean))
		return ;
	last = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last->content[i] && (last->content[i] != '\n'))
	{
		++i;
	}
	while (last->content[i] && last->content[++i])
	{
		buf[j++] = last->content[i];
	}
	buf[j] = '\0';
	clean->content = buf;
	clean->next = NULL;
	free_list(list, clean, buf);
}

void	free_list(t_list **list, t_list *clean, char *buf)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean->content[0])
		*list = clean;
	else
	{
		free(buf);
		free(clean);
	}
}
