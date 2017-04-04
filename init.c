/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:08:15 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 16:43:17 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_init_pers(t_env *e)
{
	e->pers.x = 4;
	e->pers.y = 4;
	e->pers.dir_x = -1;
	e->pers.dir_y = 0;
	e->pers.plane_x = 0;
	e->pers.plane_y = 0.66;
	e->cam.time = 0;
	e->cam.old_time = 0;
}

static void		ft_init_file(t_env *e)
{
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map = NULL;
	e->file.split = NULL;
	e->map_x = 0;
	e->map_y = 0;
}

t_env			*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 1000;
	e->win_y = 700;
	e->img = NULL;
	e->data = NULL;
	ft_init_file(e);
	ft_init_pers(e);
	return (e);
}
