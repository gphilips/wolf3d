#include "wolf3d.h"

static void		move_forward(t_env *e, int keycode)
{
	int		y;
	int		x;
	
	if (keycode == UP)
	{
		y = (int)(e->cam.pers_x - e->cam.dir_x * e->cam.speed);
		x = (int)(e->cam.pers_x);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x += e->cam.dir_x * e->cam.speed;
		ft_swap(x, y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y += e->cam.dir_y * e->cam.speed;
	}
	else if (keycode == DOWN)
	{
		y = (int)(e->cam.pers_x - e->cam.dir_x * e->cam.speed);
		x = (int)(e->cam.pers_x);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x -= e->cam.dir_x * e->cam.speed;
		ft_swap(x, y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y -= e->cam.dir_y * e->cam.speed;
	}
}

static void		move_side(t_env *e, int keycode)
{
	int		y;
	int		x;

	if (keycode == A_LEFT)
	{
		y = (int)(e->cam.pers_x - e->cam.plane_x * e->cam.speed);
		x = (int)(e->cam.pers_x);
		if (e->file.map[y][x] == 0)
			e->cam.pers_x -= e->cam.plane_x * e->cam.speed;
		ft_swap(x, y);
		if (e->file.map[y][x] == 0)
			e->cam.pers_y -= e->cam.plane_y * e->cam.speed;
	}
	else if (keycode == D_RIGHT)
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

static void		move_turn(t_env *e, int keycode)
{
	double	olddir_x;
	double	oldplane_x;

	if (keycode == RIGHT)
	{
		olddir_x = e->cam.dir_x;
		e->cam.dir_x = e->cam.dir_x * cos(e->cam.rot_speed) - e->cam.dir_y * sin(e->cam.rot_speed);
		e->cam.dir_y = olddir_x * sin(e->cam.rot_speed) + e->cam.dir_y * cos(e->cam.rot_speed);
		oldplane_x = e->cam.plane_x;
		e->cam.plane_x = e->cam.plane_x * cos(e->cam.rot_speed) - e->cam.plane_y * sin(e->cam.rot_speed);
		e->cam.plane_y = oldplane_x * sin(e->cam.rot_speed) + e->cam.plane_y * cos(e->cam.rot_speed);
	}
	if (keycode == LEFT)
	{
		olddir_x = e->cam.dir_x;
		e->cam.dir_x = e->cam.dir_x * cos(-e->cam.rot_speed) - e->cam.dir_y * sin(-e->cam.rot_speed);
		e->cam.dir_y = olddir_x * sin(-e->cam.rot_speed) + e->cam.dir_y * cos(-e->cam.rot_speed);
		oldplane_x = e->cam.plane_x;
		e->cam.plane_x = e->cam.plane_x * cos(-e->cam.rot_speed) - e->cam.plane_y * sin(-e->cam.rot_speed);
		e->cam.plane_y = oldplane_x * sin(-e->cam.rot_speed) + e->cam.plane_y * cos(-e->cam.rot_speed);
	}
}

int			move(t_env *e, int keycode)
{
	if (keycode == UP || keycode == DOWN)
		move_forward(e, keycode);
	else if (keycode == A_LEFT || keycode == D_RIGHT)
		move_side(e, keycode);
	if (keycode == LEFT || keycode == RIGHT)
		move_turn(e, keycode);
	return (0);
}
