/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:33:03 by gphilips          #+#    #+#             */
/*   Updated: 2017/06/02 19:05:44 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_texture(t_env *e)
{
	int		i;
	int		w;
	int		h;

	e->text = ft_memalloc(sizeof(t_img) * 6);
	e->texture = ft_memalloc(sizeof(char*) * 6);
	if (e->text == NULL || e->texture == NULL)
		return (-1);
	e->texture[0] = "./img/knife.xpm";
	e->texture[1] = "./img/gun.xpm";
	e->texture[2] = "./img/precision.xpm";
	e->texture[3] = "./img/gun-fire.xpm";
	e->texture[4] = "./img/sound-off.xpm";
	i = -1;
	while (e->texture[++i])
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx, e->texture[i],
				&w, &h);
		e->text[i].data = mlx_get_data_addr(e->text[i].img_ptr, &e->text[i].bpp, &e->text[i].sizeline, &e->text[i].endian);
	}
	return (0);
}

void		set_weapon(t_env *e)
{
	int		x;
	int		y;

	x = (e->win_x / 4);
	y = e->win_y - 250;
	if (e->weapon == 0)
		mlx_put_image_to_window(e->mlx, e->win, e->text[0].img_ptr, x + 100, y);
	else if (e->weapon == 1)
	{
		if (e->shot == 1)
		{
			mlx_put_image_to_window(e->mlx, e->win, e->text[3].img_ptr,
					x + 410, y);
			e->shot = 0;
		}
		mlx_put_image_to_window(e->mlx, e->win, e->text[1].img_ptr, x + 400, y);
		x = (e->win_x / 2) - 50;
		y = (e->win_y / 2) - 50;
		mlx_put_image_to_window(e->mlx, e->win, e->text[2].img_ptr, x, y);
	}
}

void	shoot(int keycode, t_env *e)
{
	if (keycode == SPC)
	{
		system("afplay musics/gunshot.mp3 -v 0.5&");
		e->shot = 1;
	}
}
