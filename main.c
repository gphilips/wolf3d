/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:04:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/02 17:09:01 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	instruction(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, "COMMANDS");
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, LINE);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FFFFFF, MOVE);
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FFFFFF, ASIDE);
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF, TABULATION);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FFFFFF, SPACE);
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF, AROBASE);
	mlx_string_put(e->mlx, e->win, 10, 130, 0x00FFFFFF, DELETE);
	mlx_string_put(e->mlx, e->win, 10, 150, 0x00FFFFFF, ENTER);
	mlx_string_put(e->mlx, e->win, 10, 170, 0x00FFFFFF, HELP);
	mlx_string_put(e->mlx, e->win, 10, 190, 0x00FFFFFF, FAST);
	mlx_string_put(e->mlx, e->win, 10, 210, 0x00FFFFFF, CLOSER);
}

int		error(int n)
{
	if (n == 1)
		ft_putendl_fd("usage: ./wold3d <map>", 2);
	if (n == 2)
		ft_putendl_fd("error: something is wrong with the file", 2);
	if (n == 3)
		ft_putendl_fd("error: bad size of the file", 2);
	if (n == 4)
		ft_putendl_fd("error: bad character in the file", 2);
	if (n == 5)
		ft_putendl_fd("error: something is wrong with textures", 2);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	int		fd;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (argc != 2)
		return (error(1));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error(2));
	e = init_all(e);
	if (read_file(fd, e) == -1)
		return (error(3));
	if ((create_int_tab(e->lst, e)) == -1)
		return (error(4));
	if ((close(fd)) == -1)
		return (error(2));
	if ((create_win(e)) == -1)
		return (error(5));
	return (0);
}
