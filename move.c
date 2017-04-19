/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:54:17 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/18 18:44:55 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		move_front_back(t_env *e)
{
	int		y;
	int		x;

	if (e->move.up == 1)
	{
		y = (int)(e->cam.pers_x + e->cam.dir_x * e->cam.speed);
		x = (int)(e->cam.pers_y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x += e->cam.dir_x * e->cam.speed;
		y = (int)(e->cam.pers_x);
		x = (int)(e->cam.pers_y + e->cam.dir_y * e->cam.speed);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y += e->cam.dir_y * e->cam.speed;
	}
	else if (e->move.down == 1)
	{
		y = (int)(e->cam.pers_x - e->cam.dir_x * e->cam.speed);
		x = (int)(e->cam.pers_y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x -= e->cam.dir_x * e->cam.speed;
		y = (int)(e->cam.pers_x);
		x = (int)(e->cam.pers_y - e->cam.dir_y * e->cam.speed);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y -= e->cam.dir_y * e->cam.speed;
	}
}

static void		move_side(t_env *e)
{
	int		y;
	int		x;

	if (e->move.s_left == 1)
	{
		y = (int)(e->cam.pers_x - e->cam.plane_x * e->cam.speed);
		x = (int)(e->cam.pers_x);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x -= e->cam.plane_x * e->cam.speed;
		ft_swap(x, y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y -= e->cam.plane_y * e->cam.speed;
	}
	else if (e->move.s_right == 1)
	{
		y = (int)(e->cam.pers_x - e->cam.plane_x * e->cam.speed);
		x = (int)(e->cam.pers_x);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x += e->cam.plane_x * e->cam.speed;
		ft_swap(x, y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y += e->cam.plane_y * e->cam.speed;
	}
}

static void		move_turn(t_env *e)
{
	double	olddir_x;
	double	oldplane_x;

	if (e->move.right == 1)
	{
		olddir_x = e->cam.dir_x;
		e->cam.dir_x = e->cam.dir_x * cos(e->cam.rot_speed) - e->cam.dir_y * sin(e->cam.rot_speed);
		e->cam.dir_y = olddir_x * sin(e->cam.rot_speed) + e->cam.dir_y * cos(e->cam.rot_speed);
		oldplane_x = e->cam.plane_x;
		e->cam.plane_x = e->cam.plane_x * cos(e->cam.rot_speed) - e->cam.plane_y * sin(e->cam.rot_speed);
		e->cam.plane_y = oldplane_x * sin(e->cam.rot_speed) + e->cam.plane_y * cos(e->cam.rot_speed);
	}
	else if (e->move.left == 1)
	{
		olddir_x = e->cam.dir_x;
		e->cam.dir_x = e->cam.dir_x * cos(-e->cam.rot_speed) - e->cam.dir_y * sin(-e->cam.rot_speed);
		e->cam.dir_y = olddir_x * sin(-e->cam.rot_speed) + e->cam.dir_y * cos(-e->cam.rot_speed);
		oldplane_x = e->cam.plane_x;
		e->cam.plane_x = e->cam.plane_x * cos(-e->cam.rot_speed) - e->cam.plane_y * sin(-e->cam.rot_speed);
		e->cam.plane_y = oldplane_x * sin(-e->cam.rot_speed) + e->cam.plane_y * cos(-e->cam.rot_speed);
	}
}

int			move(t_env *e)
{
	move_front_back(e);
	move_side(e);
	move_turn(e);
	return (0);
}
