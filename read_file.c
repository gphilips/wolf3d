/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:04:28 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 18:37:02 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_lst_push_back(t_list **list, char *line)
{
	while (*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

static int	check_size(t_env *e)
{
	int		i;
	int		flag;
	int		tmp_x;

	flag = 0;
	i = -1;
	while (e->file.split[++i])
		free(e->file.split[i]);
	if (e->file.nb_x == 0 && flag == 0)
	{
		flag = 1;
		e->file.nb_x = i;
	}
	tmp_x = i;
	if (e->file.nb_x != tmp_x || i < 4 || e->file.nb_y < 4)
		return (-1);
	return (0);
}

static int	get_size(t_env *e)
{
	t_list	*tmp;

	tmp = e->lst;
	if (tmp == NULL)
		return (-1);
	while (tmp)
	{
		e->file.split = ft_strsplit(tmp->content, ' ');
		if (e->file.split == '\0' && e->file.nb_y < 2)
			return (-1);
		if (check_size(e) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int			read_file(int fd, t_env *e)
{
	char	*line;

	e->lst = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_lst_push_back(&e->lst, line);
		e->file.nb_y++;
		free(line);
	}
	return ((get_size(e) == -1 ? -1 : 0));
}
