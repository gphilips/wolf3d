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

static void		put_pixel(t_env *e, int x, int y)
{
	int		i;

/*	e->color.b = (color & 0xFF0000) >> 16;
	e->color.g = (color & 0xFF00) >> 8;
	e->color.r = (color & 0xFF);
*/	if ((x > 0 && x < e->win_x) && (y > 0 && y < e->win_y))
	{
		i = (y * e->sizeline) + (x * e->bpp / 8);
		e->data[i] = e->color.b;
		e->data[i + 1] = e->color.g;
		e->data[i + 2] = e->color.r;
	}
}

static void		change_color(t_env *e, int r, int g, int b)
{
	e->color.r = r;
	e->color.g = g;
	e->color.b = b;
}

void			calc_height_wall(t_env *e)
{
	e->cam.line_h = (int)(e->win_y / e->cam.perp_wall);
	e->cam.start = -e->cam.line_h / 2 + e->win_y / 2;
	e->cam.end = e->cam.line_h / 2 + e->win_y / 2;
	if (e->cam.start < 0)
		e->cam.start = 0;
	if (e->cam.end >= e->win_y)
		e->cam.end = e->win_y - 1;
}

void			draw_wall(t_env *e, int x)
{
	int		y;

	y = e->cam.start;
	while (y < e->cam.end)
	{
		if (e->cam.side == 1)
			change_color(e, 200, 200, 200);
		else
			change_color(e, 255, 255, 255);
		put_pixel(e, x, y);	
		y++;
	}
}

void			draw_floor(t_env *e, int x)
{
	int		y;

	if (e->cam.end < 0)
		e->cam.end = e->win_y;
	y = e->cam.end;
	change_color(e, 100, 100, 100);
	while (y < e->win_y)
	{
		put_pixel(e, x, y);
		y++;
	}
	y = e->cam.end;
	change_color(e, 143, 212, 255);
	while (y < e->win_y)
	{
		put_pixel(e, x, e->win_y - y - 1);
		y++;
	}
}
