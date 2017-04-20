/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:52:01 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/05 15:19:38 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_gnl	*ft_create_elem(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->tmp = NULL;
	new->next = NULL;
	return (new);
}

static t_gnl	*ft_find_fd(t_gnl *list, int fd)
{
	t_gnl	*start;
	t_gnl	*tmp;

	start = list;
	while (start != NULL)
	{
		if (start->fd == fd)
			return (start);
		if (start->next == NULL)
		{
			tmp = ft_create_elem(fd);
			start->next = tmp;
			return (tmp);
		}
		start = start->next;
	}
	return (NULL);
}

static int		ft_str_to_line(char *str, char **line)
{
	char	*endline;

	endline = ft_strchr(str, '\n');
	if (endline)
	{
		*line = ft_strsub(str, 0, endline - str);
		ft_strcpy(str, endline + 1);
		return (1);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_gnl	*str = NULL;
	int				rd;
	t_gnl			*list;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!str)
		str = ft_create_elem(fd);
	list = ft_find_fd(str, fd);
	while (!(ft_strchr(list->str, '\n')))
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd == 0)
			break ;
		else if (rd < 0)
			return (-1);
		buff[rd] = '\0';
		list->tmp = ft_strjoin(list->str, buff);
		free(list->str);
		list->str = ft_strdup(list->tmp);
		free(list->tmp);
	}
	return (ft_str_to_line(list->str, line));
}
