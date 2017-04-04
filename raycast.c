#include "wolf3d.h"

void	ft_put_ray(t_env *e, t_cam c, t_pers p, int x)
{
	c.cam_x = 2 * x / (double)e->win_x - 1;
	c.ray_x = p.x;
	c.ray_y = p.y;
	c.raydir_x = e->pers.dir_x + e->pers.plane_x * e->cam_x; 
	c.raydir_y = e->pers.dir_y + e->pers.plane_y * e->cam_y;
	e->file.map_x = (int)p.x;
	e->file.map_x = (int)p.y;
	c.delta_dist_x = sqrt((c.raydir_y * c.raydir_y) + 1 / (c.raydir_x * c.raydir_x)); 
	c.delta_dist_y = sqrt((c.raydir_x * c.raydir_x) + 1 / (c.raydir_y * c.raydir_y)); 
}

void	ft_raycast(t_env *e)
{
	int		x;

	x = -1;
	while (++x < e->win_x)
	{
		ft_put_ray(e);
	}
}
