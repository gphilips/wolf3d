/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:48:36 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/04 18:49:16 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
/*
static void	instruction(t_env *e)
{
	char	*line;
	char	*zoom_in;
	char	*zoom_out;
	char	*move;
	char	*iter_p;
	char	*iter_l;
	char	*color;
	char	*ftl;

	line = "___________________";
	zoom_in = "Left Click or Scroll Up : Zoom in\n";
	zoom_out = "Right Click or Scroll Down : Zoom out\n";
	move = "Arrow keys : Move the map\n";
	iter_p = "P : Increase the precision (change the foreground color)\n";
	iter_l = "L : Lower the precision (change the foreground color)\n";
	color = "R/G/B : Change the background color\n";
	ftl = "TAB : Change the fractal\n";
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, "COMMANDS");
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, line);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FFFFFF, zoom_in);
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FFFFFF, zoom_out);
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF, move);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FFFFFF, iter_p);
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF, iter_l);
	mlx_string_put(e->mlx, e->win, 10, 130, 0x00FFFFFF, color);
	mlx_string_put(e->mlx, e->win, 10, 150, 0x00FFFFFF, ftl);
}
*/
int			expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	raycast(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
//	instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

static int	key_hook(int keycode)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == ESC)
		exit(0);
/*	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		move(e, keycode);
	expose_hook(e);
*/	return (0);
}

void		create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_putendl_fd("Error minilibx init", 2);
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Wolf 3D");
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
