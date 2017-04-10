/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:03:38 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/04 18:49:58 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_ray(t_env *e, int x)
{
	e->cam.cam_x = (2 * x / (double)(e->win_x)) - 1;
	e->cam.ray_x = e->cam.pers_x;
	e->cam.ray_y = e->cam.pers_y;
	e->cam.raydir_x = e->cam.dir_x + e->cam.plane_x * e->cam.cam_x;
	e->cam.raydir_y = e->cam.dir_y + e->cam.plane_y * e->cam.cam_x;
	e->file.map_x = (int)(e->cam.ray_x);
	e->file.map_y = (int)(e->cam.ray_y);
	e->cam.ddist_x = sqrt(1 + (e->cam.raydir_y * e->cam.raydir_y) / (e->cam.raydir_x * e->cam.raydir_x));
	e->cam.ddist_y = sqrt(1 + (e->cam.raydir_x * e->cam.raydir_x) / (e->cam.raydir_y * e->cam.raydir_y));
	e->cam.hit = 0;
}

static void		step_to_wall(t_env *e)
{
	if (e->cam.raydir_x < 0)
	{
		e->cam.step_x = -1;
		e->cam.sdist_x = (e->cam.ray_x - e->file.map_x) * e->cam.ddist_x;
	}
	else
	{
		e->cam.step_x = 1;
		e->cam.sdist_x = (e->file.map_x + 1.0 - e->cam.ray_x) * e->cam.ddist_x;
	}
	if (e->cam.raydir_y < 0)
	{
		e->cam.step_y = -1;
		e->cam.sdist_y = (e->cam.ray_y -e->file.map_y) * e->cam.ddist_y;
	}
	else
	{
		e->cam.step_y = 1;
		e->cam.sdist_y = (e->file.map_y + 1.0 - e->cam.ray_y) * e->cam.ddist_y;
	}
}

static void		hit_wall(t_env *e)
{
	while (e->cam.hit == 0)
	{
		if (e->cam.sdist_x < e->cam.sdist_y
			&& (e->cam.sdist_x >= 0 || e->cam.sdist_y <= 0))
		{
			e->cam.sdist_x += e->cam.ddist_x;
			e->file.map_x += e->cam.step_x;
			e->cam.side = 0;
		}
		else
		{
			e->cam.sdist_y += e->cam.ddist_y;
			e->file.map_y += e->cam.step_y;
			e->cam.side = 1;
		}
		if (e->file.map[e->file.map_x][e->file.map_y] != 0)
			e->cam.hit = 1;
	}
}

static void		correct_dist(t_env *e)
{
	double	sqr_crossed_x;
	double	sqr_crossed_y;
	
	if (e->cam.side == 0)
	{
		sqr_crossed_x = e->file.map_x - e->cam.ray_x + (1 - e->cam.step_x) / 2;
		e->cam.perp_wall = sqr_crossed_x / e->cam.raydir_x;
	}
	else if (e->cam.side == 1)
	{
		sqr_crossed_y = e->file.map_y - e->cam.ray_y + (1 - e->cam.step_y) / 2;
		e->cam.perp_wall = sqr_crossed_y / e->cam.raydir_y;
	}
}

void			raycast(t_env *e)
{
	int		x;

	x = -1;
	while (++x < e->win_x)
	{
		set_ray(e, x);
		step_to_wall(e);
		hit_wall(e);
		correct_dist(e);
		calc_height_wall(e);
		draw_wall(e, x);
		draw_sky_floor(e, x);
	}
}
