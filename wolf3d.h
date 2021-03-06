/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:03:01 by gphilips          #+#    #+#             */
/*   Updated: 2017/08/16 16:15:42 by gphilips         ###   ########.fr       */
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

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ENT 36
# define H 4
# define Q_LEFT 12
# define E_RIGHT 14
# define TAB 48
# define AT 50
# define DEL 51
# define SPC 49
# define SHIFT 257
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L<<1)
# define CLOSE 17
# define CLOSEMASK (1L<<17)
# define OFFSET 4

# define LINE "___________________"
# define MOVE "UP|DOWN|LEFT|RIGHT : Move\n"
# define ASIDE "Q|E : Move aside\n"
# define TABULATION "TAB : Change the gun\n"
# define SPACE "SPACE : Shoot with the gun\n"
# define AROBASE "BACKTICK : Change the music\n"
# define DELETE "DEL : Turn off the music\n"
# define ENTER "ENTER : Open secret doors\n"
# define HELP "H : Get instruction\n"
# define FAST "SHIFT : Move faster\n"
# define CLOSER "ESC|RED_BTN : Turn off the game\n"

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
	double	wall_x;
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

typedef struct	s_img
{
	void	*img_ptr;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*data;
}				t_img;

typedef struct	s_env
{
	int		win_x;
	int		win_y;
	void	*mlx;
	void	*win;
	char	**texture;
	int		sound;
	int		weapon;
	int		shot;
	int		instruction;
	t_img	img;
	t_img	*text;
	t_list	*lst;
	t_file	file;
	t_cam	cam;
	t_color	color;
	t_move	move;
}				t_env;

t_env			*init_all(t_env *e);
int				read_file(int fd, t_env *e);
int				create_int_tab(t_list *lst, t_env *e);
void			instruction(t_env *e);

void			raycast(t_env *e);
void			change_color(t_env *e, int r, int g, int b);
void			put_pixel(t_env *e, int x, int y);
void			calc_height_wall(t_env *e);
void			draw_wall(t_env *e, int x);
void			draw_sky_floor(t_env *e, int x);
int				init_texture(t_env *e);

int				move(t_env *e);
void			draw_minimap(t_env *e);
void			change_sound(int keycode, t_env *e);
void			set_weapon(t_env *e);
void			shoot(int keycode, t_env *e);
void			open_door(int keycode, t_env *e);
void			key_onpress(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);
int				create_win(t_env *e);

int				error(int n);
void			free_node(void *content, size_t size);
void			free_map(t_env *e);
#endif
