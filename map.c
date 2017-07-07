/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:43:24 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/19 18:47:34 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_num(t_env *e, int x)
{
	if (*e->file.split[x] != '1' && *e->file.split[x] != '0'
		&& *e->file.split[x] != '2')
		return (-1);
	return (0);
}

int			create_int_tab(t_list *lst, t_env *e)
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
			if ((check_num(e, x)) == -1)
				return (-1);
			e->file.map[y][x] = ft_atoi(e->file.split[x]);
			free(e->file.split[x]);
		}
		lst = lst->next;
	}
	free(e->file.split);
	ft_lstdel(start, free_node);
	return (0);
}
