/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:48:36 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 18:20:32 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	quit(t_env *e)
{
	int		i;

	if (e->sound != 0)
		system("killall afplay");
	i = -1;
	while (e->texture[++i])
		mlx_destroy_image(e->mlx, e->text[i].img_ptr);
	mlx_destroy_window(e->mlx, e->win);
	free_map(e);
	free(e->text);
	free(e->texture);
	free(e);
	exit(0);
	return (0);
}

int			expose_hook(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img.data = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
			&e->img.sizeline, &e->img.endian);
	raycast(e);
	move(e);
	draw_minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	if (e->sound == 0)
	{
		mlx_put_image_to_window(e->mlx, e->win,
				e->text[4].img_ptr, 10, 665);
	}
	set_weapon(e);
	mlx_destroy_image(e->mlx, e->img.img_ptr);
	if (e->instruction == 1)
		instruction(e);
	return (0);
}

static int	key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
		quit(e);
	else if (keycode == AT || keycode == DEL)
		change_sound(keycode, e);
	else if (keycode == TAB)
		e->weapon = (e->weapon == 0) ? 1 : 0;
	else if (keycode == SPC && e->weapon == 1)
		shoot(keycode, e);
	else if (keycode == ENT)
		open_door(keycode, e);
	else if (keycode == SHIFT)
		e->cam.speed = 0.15;
	else if (keycode == H)
		e->instruction = (e->instruction == 0) ? 1 : 0;
	key_onpress(keycode, e);
	expose_hook(e);
	return (0);
}

int			create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putendl_fd("Error minilibx init", 2);
		return (-1);
	}
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Wolf 3D");
	if ((init_texture(e)) == -1)
		return (-1);
	mlx_hook(e->win, CLOSE, CLOSEMASK, quit, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_press, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASEMASK, key_release, e);
	mlx_loop_hook(e->mlx, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
