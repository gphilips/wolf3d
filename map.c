/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:43:24 by gphilips          #+#    #+#             */
/*   Updated: 2017/03/29 19:18:50 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	**ft_create_int_tab(t_list *lst, t_env *e)
{
	int		x;
	int		y;
	t_list **start;

	start = &lst;
	e->file.map = (t_map**)ft_memalloc(sizeof(t_map*) * e->file.nb_y);
	y = -1;
	while (++y < e->file.nb_y)
	{
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		e->file.map[y] = (t_map*)ft_memalloc(sizeof(t_map) * e->file.nb_x);
		x = -1;
		printf("TAB :\n");
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x].type = ft_atoi(e->file.split[x]);
			free(e->file.split[x]);
			printf("%d", e->file.map[y][x].type);
		}
		lst = lst->next;
		printf("\n");
	}
	free(e->file.split);
//	ft_lstdel(start, ft_free_node);
	return (e->file.map);
}
