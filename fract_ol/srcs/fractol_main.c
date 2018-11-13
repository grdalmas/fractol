/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:49:40 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/15 14:53:42 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void			verif_argv(char *s, t_env *env)
{
	if (!(ft_strcmp(s, "julia")))
		env->main2 = 1;
	else if (!(ft_strcmp(s, "mandelbrot")))
		env->main2 = 2;
	else if (!(ft_strcmp(s, "mandelbar")))
		env->main2 = 3;
	else if (!(ft_strcmp(s, "burningship")))
		env->main2 = 4;
	else if (!(ft_strcmp(s, "celtic")))
		env->main2 = 5;
	if (!(ft_strcmp(s, "julia")))
		env->ft = &julia;
	else if (!(ft_strcmp(s, "mandelbrot")))
		env->ft = &mandelbrot;
	else if (!(ft_strcmp(s, "mandelbar")))
		env->ft = &mandelbar;
	else if (!(ft_strcmp(s, "burningship")))
		env->ft = &burning_ship;
	else if (!(ft_strcmp(s, "celtic")))
		env->ft = &celtic;
	else
		ft_error(USAGE);
}

int				windows_exit(t_env *env)
{
	
	(void)env;
	ft_error("See you again, space clodo!!");
	return (0);
}

int				main(int argc, char **argv)
{
	t_env			env;

	if (argc == 1 || argc >= 4)
		ft_error(USAGE);
	if (argc == 3)
		if (ft_atoi(argv[2]) >= 0)
			env.i_max = ft_atoi(argv[2]);
	if (argc == 2)
		env.i_max = 50;
	verif_argv(argv[1], &env);
	fract_init(&env);
	fract_new_image(&env);
	fractal_print(&env);
	mlx_hook(env.win, 2, 1L << 1, fract_key, &env);
	mlx_hook(env.win, 6, 1L << 6, mouse_position, &env);
	mlx_hook(env.win, 17, 1L << 17, windows_exit, &env);
	mlx_mouse_hook(env.win, ft_key_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}
