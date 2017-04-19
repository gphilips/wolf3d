/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:26:40 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/19 18:56:42 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_minimap(t_env *e)
{
	int 	y;
	int		x;

	y = -1;
	while (++y < e->win_y - (e->win_y / 4))
	{
		x = -1;
		while (++x < e->win_x - (e->win_x / 4))
		{
//			printf("%d", e->file.map[y][x]);
			if (e->file.map[y][x] == 1)
			{
				change_color(e, 200, 200, 200);
				put_pixel(e, x, y);
			}
			else if (e->file.map[y][x] == 0)
			{
				change_color(e, 255, 255, 255);
				put_pixel(e, x, y);
			}
			change_color(e, 255, 0, 0);
			put_pixel(e, e->cam.pers_x, e->cam.pers_y);
		}
	}
}
