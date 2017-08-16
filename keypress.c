/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:15:57 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/11 16:55:27 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_onpress(int keycode, t_env *e)
{
	if (keycode == UP)
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
}

int		key_release(int keycode, t_env *e)
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
	else if (keycode == SHIFT)
		e->cam.speed = 0.1;
	return (0);
}
