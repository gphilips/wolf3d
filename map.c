/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:43:24 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 16:30:34 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_num(t_env *e, int x, int y)
{
	t_file	f;

	f = e->file;
	if (f.map[y][x] != 1 || f.map[y][x] != 0
		|| f.map[y][x] != '\n' || f.map[y][x] != '\0')
		return (-1);
	return (0);
}

int		ft_create_int_tab(t_list *lst, t_env *e)
{
	int		x;
	int		y;
	t_list	**start;

	start = &lst;
	e->file.map = (int**)ft_memalloc(sizeof(int*) * e->file.nb_y);
	y = -1;
	while (++y < e->file.nb_y)
	{
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		e->file.map[y] = (int*)ft_memalloc(sizeof(int) * e->file.nb_x);
		x = -1;
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x] = ft_atoi(e->file.split[x]);
			free(e->file.split[x]);
			ft_check_num(e, x, y);
		}
		lst = lst->next;
	}
	free(e->file.split);
	ft_lstdel(start, ft_free_node);
	return (0);
}
