/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:43:24 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 18:53:30 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_num(t_env *e, int x)
{
	if (*e->file.split[x] != '1' && *e->file.split[x] != '0'
		&& *e->file.split[x] != '2')
		return (-1);
	return (0);
}

static int	check_zero(t_env *e, int **tab)
{
	int	x;
	int	y;
	int	zero;

	zero = 0;
	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (tab[y][x] == 0)
			{
				zero++;
				if (zero == 2)
				{
					e->cam.pers_y = y + 1;
					e->cam.pers_x = x;
				}
			}
		}
	}
	return (zero);
}

static int	check_border(t_env *e, int **tab)
{
	int	y;
	int	x;
	int	flag;

	flag = 0;
	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (tab[0][x] == 0 || tab[e->file.nb_y - 1][x] == 0
				|| tab[y][0] == 0 || tab[y][e->file.nb_x - 1] == 0)
				flag++;
		}
	}
	return (flag);
}

static int	add_line(t_env *e, int y)
{
	int		x;

	x = -1;
	while (++x < e->file.nb_x)
	{
		if ((check_num(e, x)) == -1)
			return (-1);
		e->file.map[y][x] = ft_atoi(e->file.split[x]);
		free(e->file.split[x]);
	}
	return (0);
}

int			create_int_tab(t_list *lst, t_env *e)
{
	int		y;
	t_list	**start;
	char	**tmp;

	start = &lst;
	e->file.map = (int**)ft_memalloc(sizeof(int*) * e->file.nb_y);
	y = -1;
	while (++y < e->file.nb_y)
	{
		tmp = e->file.split;
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		free(tmp);
		e->file.map[y] = (int*)ft_memalloc(sizeof(int) * e->file.nb_x);
		add_line(e, y);
		lst = lst->next;
	}
	if (check_zero(e, e->file.map) == 0 || check_border(e, e->file.map) != 0)
		return (-1);
	free(e->file.split);
	ft_lstdel(start, free_node);
	return (0);
}
