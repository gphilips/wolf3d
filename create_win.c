/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:48:36 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/19 18:49:36 by gphilips         ###   ########.fr       */
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

static int 	quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}
/*
int			mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	if (button == 1)
		printf("x : %d y : %d\n", x, y);
	return (0);
}
*/
int			expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	raycast(e);
	move(e);
	draw_minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
//	instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

static int	key_press(int keycode, t_env *e)
{
/*	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
*/	if (keycode == ESC)
		quit(e);
	else if (keycode == UP)
		e->move.up = 1;
	else if (keycode == DOWN)
		e->move.down = 1;
	else if (keycode == LEFT)
		e->move.left = 1;
	else if (keycode == RIGHT)
		e->move.right = 1;
	else if (keycode == Q_LEFT)
		e->move.s_left = 1;
	else if (keycode == E_RIGHT)
		e->move.s_right = 1;
	expose_hook(e);
	return (0);
}

static int	key_release(int keycode, t_env *e)
{
	if (keycode == UP)
		e->move.up = 0;
	else if (keycode == DOWN)
		e->move.down = 0;
	else if (keycode == LEFT)
		e->move.left = 0;
	else if (keycode == RIGHT)
		e->move.right = 0;
	else if (keycode == Q_LEFT)
		e->move.s_left = 0;
	else if (keycode == E_RIGHT)
		e->move.s_right = 0;
	return (0);
}

void		create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_putendl_fd("Error minilibx init", 2);
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Wolf 3D");
	mlx_hook(e->win, CLOSE, CLOSEMASK, quit, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_press, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASEMASK, key_release, e);
//	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, expose_hook, e);
	mlx_loop(e->mlx);
}
