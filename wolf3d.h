/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:03:01 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/19 17:42:10 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# include <stdio.h>

# define ESC 53
# define P 35
# define L 37
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ENT 36
# define CLICK_L 1
# define CLICK_R 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define Q_LEFT 12
# define E_RIGHT 14
# define R 15
# define G 5
# define B 11
# define TAB 48
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<2)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L<<1)
# define CLOSE 17
# define CLOSEMASK (1L<<17)
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)

typedef struct	s_move
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		s_left;
	int		s_right;
}				t_move;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_cam
{
	double	pers_x;
	double	pers_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	double	raydir_x;
	double	raydir_y;
	double	plane_x;
	double	plane_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	double	perp_wall;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		start;
	int		end;
	float	speed;
	float	rot_speed;
}				t_cam;

typedef struct	s_file
{
	int		nb_x;
	int		nb_y;
	int		**map;
	int		map_x;
	int		map_y;
	char	**split;
}				t_file;

typedef struct	s_env
{
	int		win_x;
	int		win_y;
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*data;
	int		ftl;
	t_list	*lst;
	t_file	file;
	t_cam	cam;
	t_color	color;
	t_move	move;
}				t_env;

t_env	*init_all(t_env *e);
int		read_file(int fd, t_env *e);
int		create_int_tab(t_list *lst, t_env *e);

void	raycast(t_env *e);
void	change_color(t_env *e, int r, int g, int b);
void	put_pixel(t_env *e, int x, int y);
void	calc_height_wall(t_env *e);
void	draw_wall(t_env *e, int x);
void	draw_sky_floor(t_env *e, int x);

int		move(t_env *e);
void	draw_minimap(t_env *e);
void	create_win(t_env *e);

void	free_node(void *content, size_t size);
void	free_map(t_env *e);
#endif
