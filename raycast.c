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

static void		ft_calc_ray(t_env *e, t_file f, t_cam c, int x)
{
	c.cam_x = 2 * x / (double)e->win_x - 1;
	c.ray_x = c.x;
	c.ray_y = c.y;
	c.raydir_x = c.dir_x + c.plane_x * c.cam_x;
	c.raydir_y = c.dir_y + c.plane_y * c.cam_x;
	f.map_x = (int)c.ray_x;
	f.map_x = (int)c.ray_y;
	c.ddist_x = sqrt((c.raydir_y * c.raydir_y) + 1 / (c.raydir_x * c.raydir_x));
	c.ddist_y = sqrt((c.raydir_x * c.raydir_x) + 1 / (c.raydir_y * c.raydir_y));
}

static void		ft_calc_side_dist(t_file f, t_cam c)
{
	if (c.raydir_x < 0)
	{
		c.step_x = -1;
		c.sdist_x = (c.ray_x - f.map_x) * c.ddist_x;
	}
	else
	{
		c.step_x = 1;
		c.sdist_x = (f.map_x + 1 - c.ray_x) * c.ddist_x;
	}
	if (c.raydir_y < 0)
	{
		c.step_y = -1;
		c.sdist_y = (c.ray_y - f.map_y) * c.ddist_y;
	}
	else
	{
		c.step_y = 1;
		c.sdist_y = (f.map_y + 1 - c.ray_x) * c.ddist_y;
	}
}

static void		ft_hit_wall(t_file f, t_cam c)
{
	while (c.hit == 0)
	{
		if (c.sdist_x < c.sdist_y)
		{
			c.sdist_x += c.ddist_x;
			f.map_x += c.step_x;
			c.side = 0;
		}
		else
		{
			c.sdist_y += c.ddist_y;
			f.map_y += c.step_y;
			c.side = 1;
		}
		if (f.map[f.map_y][f.map_x] > 0)
			c.hit = 1;
	}
}

static void		ft_dist_wall(t_file f, t_cam c)
{
	if (c.side == 0)
		c.perp_wall = (f.map_x - c.ray_x + (1 - c.step_x) / 2) / c.raydir_x;
	else
		c.perp_wall = (f.map_y - c.ray_y + (1 - c.step_y) / 2) / c.raydir_y;
}

void			ft_raycast(t_env *e)
{
	int		x;

	x = -1;
	while (++x < e->win_x)
	{
		ft_calc_ray(e, e->file, e->cam, x);
		ft_calc_side_dist(e->file, e->cam);
		ft_hit_wall(e->file, e->cam);
	}
}
