/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:54:25 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 16:49:35 by gphilips         ###   ########.fr       */
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
