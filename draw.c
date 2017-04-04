/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:54:25 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/04 18:59:08 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_put_pixel(t_env *e, int x, int y, int color)
{
	int		i;

	e->color.b = (color & 0xFF0000) >> 16;
	e->color.g = (color & 0xFF00) >> 8;
	e->color.r = (color & 0xFF);
	if ((x > 0 && x < e->win_x) && (y > 0 && y < e->win_y))
	{
		i = (y * e->sizeline) + (x * e->bpp / 8);
		e->data[i] = e->color.b;
		e->data[i + 1] = e->color.g;
		e->data[i + 2] = e->color.r;
	}
}

void			ft_draw_map(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (e->file.map[y][x] == 1)
				ft_put_pixel(e, x, y, 20);
			else if (e->file.map[y][x] == 0)
				ft_put_pixel(e, x, y, 200);
		}
	}
}

void			ft_draw_wall(t_env *e, t_cam c)
{
	int		line_h;
	int		start;
	int		end;

	line_h = (int)(e->win_y / c.perp_wall);
	start = -line_h / 2 + e->win_y / 2;
	if (start < 0)
		start = 0;
	end = line_h / 2 + e->win_y / 2;
	if (end >= e->win_y)
		end = e->win_y - 1;
}

