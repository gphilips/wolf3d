/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:08:15 by gphilips          #+#    #+#             */
/*   Updated: 2017/03/31 17:52:28 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_init_file(t_env *e)
{
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map = NULL;
	e->file.split = NULL;
}

t_env			*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 0;
	e->win_y = 0;
	e->img = NULL;
	e->data = NULL;
	ft_init_file(e);
	return (e);
}
