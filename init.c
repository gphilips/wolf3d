/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:08:15 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/21 18:26:12 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_color(t_env *e)
{
	e->color.r = 0;
	e->color.g = 0;
	e->color.b = 0;
}

static void		init_cam(t_env *e)
{
	e->cam.pers_x = 3;
	e->cam.pers_y = 3;
	e->cam.dir_x = 1;
	e->cam.dir_y = 0;
	e->cam.plane_x = 0;
	e->cam.plane_y = 0.66;
	e->cam.speed = 0.1;
	e->cam.rot_speed = 0.05;
}

static void		init_file(t_env *e)
{
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map = NULL;
	e->file.split = NULL;
	e->file.map_x = 0;
	e->file.map_y = 0;
}

t_env			*init_all(t_env *e)
{
	e->win_x = 1300;
	e->win_y = 700;
	e->mlx = NULL;
	e->win = NULL;
	e->img.img_ptr = NULL;
	e->img.data = NULL;
	e->texture = NULL;
	e->sound = 0;
	init_file(e);
	init_cam(e);
	init_color(e);
	return (e);
}
