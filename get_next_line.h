/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:02:07 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/14 15:03:07 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		search_nl(t_list *list);
int		len_to_nl(t_list *list);
void	buf_to_line(t_list *list, char *line);
void	free_list(t_list **list, t_list *clean, char *buf);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, void *content);

#endif
