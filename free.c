/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:42:17 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 14:53:52 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_node(void *content, size_t size)
{
	free(content);
	content = NULL;
	size = 0;
}

void	ft_free_map(t_env *e)
{
	int		y;

	y = -1;
	while (++y < e->file.nb_y)
		free(e->file.map[y]);
	free(e->file.map);
	e->file.map = NULL;
}
