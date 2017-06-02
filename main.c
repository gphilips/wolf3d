/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:04:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/06/02 15:56:35 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		return (error(1) == -1 ? -1 : 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error(2) == -1 ? -1 : 0);
	e = init_all(e);
	if (read_file(fd, e) == -1)
		return (error(3) == -1 ? -1 : 0);
	if ((create_int_tab(e->lst, e)) == -1)
		return (error(4) == -1 ? -1 : 0);
	if ((close(fd)) == -1)
		return (error(2) == -1 ? -1 : 0);
	if ((create_win(e)) == -1)
		return (error(5) == -1 ? -1 : 0);
	return (0);
}
