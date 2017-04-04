/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:04:28 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 16:27:15 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_lst_push_back(t_list **list, char *line)
{
	while(*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

static int	ft_get_size(t_env *e)
{
	t_list	*tmp;
	int		flag;
	int		tmp_x;
	int		i;

	flag = 0;
	tmp = e->lst;
	while (tmp)
	{
		e->file.split = ft_strsplit(tmp->content, ' ');
		i = -1;
		while (e->file.split[++i])
			free(e->file.split[i]);
		if (e->file.nb_x == 0 && flag == 0)
		{
			flag = 1;
			e->file.nb_x = i;
		}
		tmp_x = i;
		if (e->file.nb_x != tmp_x)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_read_file(int fd, t_env *e)
{
	char	*line;

	e->lst = NULL;
	line = NULL;
	if (get_next_line(fd, &line) < 1)
		return (-1);
	e->lst = ft_lstnew(line, ft_strlen(line) + 1);
	free(line);
	e->file.nb_y++;
	while (get_next_line(fd, &line))
	{
		ft_lst_push_back(&e->lst, line);
		e->file.nb_y++;
		free(line);
	}
	return ((ft_get_size(e) == -1 ? -1 : 0));
}
