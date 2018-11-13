/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:50:00 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 22:50:48 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define MAX_X 1000
# define MAX_Y 600
# define NAME "Le Fract'ol de l'Ennui!!"
# define USAGE "usage : ./fractol mandelbrot, julia or burningship"
# define WHITE 0xFFFFFF
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define ENTER 36
# define SPACE 49
# define KEY_1  18
# define KEY_2  19
# define KEY_3  20
# define KEY_4  21
# define I 34
# define M 46
# define N 45
# define O 31
# define M_PLUS 4
# define M_MINUS 5
# define M_LEFT 1
# define M_RIGHT 2
# define FOIS 67
# define ELEVEN 27
# define J	38
# define H 4
# define V 9

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	void			*img_2;
	char			*data_2;
	int				b_2;
	int				l_2;
	int				(*ft)(struct s_env*, int);
	int				julia;
	int				mandelbrot;
	int				info;
	int				info_i;
	int				mod_i;
	int				main;
	int				main2;
	int				main3;
	int				main4;
	int				color;
	int				key_m;
	int				tmpx;
	int				tmpy;
	int				tmpz;
	int				key_h;
	int				key_v;
	int				save_x_m;
	int				save_y_m;
	char			*str;
	int				k;
	int				i;
	int				mod_j;
	int				save_x;
	int				save_y;
	int				lock;
	int				i_max;
	double			zoom;
	double			ox;
	double			oy;
	double			xx;
	double			yy;
	double			zi;
	double			zr;
	double			cr;
	double			ci;
	long double		tmp_zi;
	int				x;
	int				y;
	int				b;
	int				l;
	double			tmp_x;
	double			tmp_y;
	double			tmp_z;
	double			tmp_xx;
	double			tmp_yy;
	int				nb_zoom;
}					t_env;

/*
**					fractol_init.c
*/
void				fract_new_image(t_env *env);
void				fractol_init_var(t_env *env);
void				ft_init_info(t_env *env);
void				fract_init(t_env *env);

/*
**					fractol_put_img.c
*/
int					choose_color(t_env *env);
void				play_color(t_env *env, int k, int i);
void				fractal_print(t_env *env);

/*
**					fractals.c
*/
int					julia(t_env *env, int i);
int					mandelbrot(t_env *env, int i);
int					mandelbar(t_env *env, int i);
int					burning_ship(t_env *env, int i);
int					celtic(t_env *env, int i);

/*
**					fractol_key_hooks.c
*/
void				fract_key_menu(int k, t_env *env);
void				fract_key_move(int k, t_env *env);
void				frat_key_2(int k, t_env *env);
int					fract_key(int k, t_env *env);

/*
**					fractol_mouse_params.c
*/
void				ft_resize(t_env *env, int x, int y, char c);
int					ft_key_mouse(int k, int x, int y, t_env *env);
void				move_to_mouse(t_env *env, int x, int y, int c);
void				main_menu_intera(t_env *env, int x, int y);
int					mouse_position(int x, int y, t_env *env);

/*
**					fractol_menu.c
*/
void				ft_menu4(int keycode, t_env *env);
void				ft_menu2(int keycode, t_env *env, int c);
void				ft_menu3(t_env *env);
void				ft_menu(int keycode, t_env *env, int c);
int					ft_zoom(t_env *env);

/*
**					fractol__print_menu.c
*/
void				ft_print_info_3(t_env *env);
void				ft_print_info_2(t_env *env);
void				ft_print_info(t_env *env);
void				ft_print_color_info(t_env *env);

/*
**					fractol_print_menu_2.c
*/
void				ft_print_sub_menu(t_env *env);
void				ft_print_menu(t_env *env);
void				ft_print_info_menu(t_env *env);

/*
**					fractol_main.c
*/
void				ft_error(char *str);
void				ft_print_help(t_env *env);
int					main(int argc, char **argv);
int					windows_exit(t_env *env);

#endif
