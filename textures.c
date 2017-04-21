/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:33:03 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/21 19:29:36 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
/*
static void		init_texture(t_env *e)
{
	e->texture = ft_memalloc(sizeof(char*) * 1);
	e->texture[0] = "img/sky.xpm";
}

void			print_texture(t_env *e)
{
	int		i;

	i = -1;
	init_texture(e);
	e->text = ft_memalloc(sizeof(t_img) * 1);
	while (++i < 1)
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx, e->texture[i], 0, 0);
		e->text[i].data = mlx_get_data_addr(e->text[i].img_ptr, &e->text[i].bpp, &e->text[i].sizeline, &e->text[i].endian);
//		mlx_put_image_to_window(e->mlx, e->win, e->text[i].img_ptr, 0, 0);
	}
}*/
