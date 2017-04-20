/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:26:40 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/19 18:56:42 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_tile(t_env *e, int y, int x)
{
	int		i;
	int		j;
	int		pos_y;
	int		pos_x;

	pos_y = e->win_y - (OFFSET * e->file.nb_y);
	pos_x = e->win_x - (25 + (OFFSET * e->file.nb_x));
	j = -1;
	while (++j <= OFFSET)
	{
		i = -1;
		while (++i <= OFFSET)
			put_pixel(e, pos_x + (x + i), pos_y + (y + j));
	}
}

void			draw_minimap(t_env *e)
{
	int 	y;
	int		x;
	int		pos_x;
	int		pos_y;

	pos_y = e->cam.pers_x;
	pos_x = e->cam.pers_y;
	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (e->file.map[y][x] == 1)
				change_color(e, 0, 0, 0);
			else if (y == pos_y && x == pos_x)
				change_color(e, 255, 0, 0);
			else
				change_color(e, 255, 255, 255);
			draw_tile(e, OFFSET * y, OFFSET * x);
		}
	}
}
