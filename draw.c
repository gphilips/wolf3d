/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:54:25 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 17:09:40 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(t_env *e, int x, int y)
{
	int		i;

	if ((x > 0 && x < e->win_x) && (y > 0 && y < e->win_y))
	{
		i = (y * e->img.sizeline) + (x * e->img.bpp / 8);
		e->img.data[i] = e->color.b;
		e->img.data[i + 1] = e->color.g;
		e->img.data[i + 2] = e->color.r;
	}
}

void	change_color(t_env *e, int r, int g, int b)
{
	e->color.r = r;
	e->color.g = g;
	e->color.b = b;
}

void	calc_height_wall(t_env *e)
{
	e->cam.line_h = (int)(e->win_y / e->cam.perp_wall);
	e->cam.start = -e->cam.line_h / 2 + e->win_y / 2;
	e->cam.end = e->cam.line_h / 2 + e->win_y / 2;
	if (e->cam.start < 0)
		e->cam.start = 0;
	if (e->cam.end >= e->win_y)
		e->cam.end = e->win_y - 1;
}

void	draw_wall(t_env *e, int x)
{
	int		y;

	y = e->cam.start;
	while (y < e->cam.end)
	{
		change_color(e, 232, 169, 133);
		if (e->cam.side == 0 && e->cam.step_x == 1)
			change_color(e, 200, 200, 200);
		else if (e->cam.side == 0 && e->cam.step_x == -1)
			change_color(e, 255, 255, 255);
		else if (e->cam.side == 1 && e->cam.step_y == 1)
			change_color(e, 120, 175, 255);
		put_pixel(e, x, y);
		y++;
	}
}

void	draw_sky_floor(t_env *e, int x)
{
	int		y;

	y = 0;
	change_color(e, 143, 212, 255);
	while (y < e->cam.start)
		put_pixel(e, x, y++);
	y = e->cam.end;
	change_color(e, 100, 100, 100);
	while (y < e->win_y)
		put_pixel(e, x, y++);
}
