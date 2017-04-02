/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:04:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 16:30:27 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_error(int n)
{
	if (n == 1)
		ft_putendl_fd("usage: ./wold3d <map>", 2);
	if (n == 2)
		ft_putendl_fd("error: something is wrong with the file", 2);
	if (n == 3)
		ft_putendl_fd("error: bad size of the file", 2);
	if (n == 4)
		ft_putendl_fd("error: bad character in the file", 2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env	*e;
	int		fd;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (argc != 2)
		return (ft_error(1) == -1 ? -1 : 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error(2) == -1 ? -1 : 0);
	e = ft_init_all(e);
	if (ft_read_file(fd, e) == -1)
		return (ft_error(3) == -1 ? -1 : 0);
	if ((ft_create_int_tab(e->lst, e)) == -1)
		return (ft_error(4) == -1 ? -1 : 0);
	ft_create_win(e);
	if ((close(fd)) == -1)
		return (ft_error(2) == -1 ? -1 : 0);
	ft_free_map(e);
	return (0);
}
