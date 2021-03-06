/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:55:48 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 17:08:27 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	reset_sound(int number, t_env *e)
{
	system("killall afplay");
	e->sound = number;
}

void		change_sound(int keycode, t_env *e)
{
	if (keycode == DEL && e->sound != 0)
		reset_sound(0, e);
	else if (keycode == AT)
	{
		if (e->sound > 2)
			reset_sound(1, e);
		else
			e->sound++;
	}
	if (e->sound == 1)
		system("afplay musics/commas.mp3 -v 0.3&");
	else if (e->sound == 2)
	{
		system("killall afplay");
		system("afplay musics/mask-off.mp3 -v 0.3&");
	}
	else if (e->sound == 3)
	{
		system("killall afplay");
		system("afplay musics/blase.mp3 -v 0.3&");
	}
}

void		open_door(int keycode, t_env *e)
{
	int	y;
	int	x;

	y = (int)(e->cam.pers_x + e->cam.dir_x * e->cam.speed);
	x = (int)(e->cam.pers_y);
	if (keycode == ENT && e->file.map[y][x] == 2)
		e->file.map[y][x] = 0;
}
