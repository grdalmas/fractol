/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:39:21 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 18:14:17 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_menu4(int keycode, t_env *env)
{
	if (env->main4 == 1 && keycode == UP)
		env->main4 = 4;
	else if (env->main4 == 4 && keycode == DOWN)
		env->main4 = 1;
	else if (keycode == UP)
		env->main4 -= 1;
	else
		env->main4 += 1;
}

void		ft_menu2(int keycode, t_env *env, int c)
{
	if (c == 2)
	{
		if (c == 2 && keycode == ENTER)
			env->main *= -1;
		if (env->main2 == 1)
			env->ft = &julia;
		if (env->main2 == 2)
			env->ft = &mandelbrot;
		if (env->main2 == 3)
			env->ft = &mandelbar;
		if (env->main2 == 4)
			env->ft = &burning_ship;
		if (env->main2 == 5)
			env->ft = &celtic;
		fractol_init_var(env);
	}
	else if (c == 3)
		ft_menu4(keycode, env);
}

void		ft_menu3(t_env *env)
{
	fractol_init_var(env);
	if (env->main4 == 1)
	{
		env->cr = -0.0986;
		env->ci = -0.65186;
		env->i_max = 115;
	}
	if (env->main4 == 2)
	{
		env->cr = -0.70176;
		env->ci = -0.3842;
	}
	if (env->main4 == 3)
	{
		env->cr = -0.772691322542185;
		env->ci = 0.124281466072787;
		env->i_max = 83;
	}
	if (env->main4 == 4)
	{
		env->cr = -0.8;
		env->ci = 0.156;
	}
	fractal_print(env);
}

void		ft_menu(int keycode, t_env *env, int c)
{
	if (c == 1)
	{
		if (env->main2 == 1 && keycode == UP)
			env->main2 = 5;
		else if (env->main2 == 5 && keycode == DOWN)
			env->main2 = 1;
		else if (keycode == UP)
			env->main2 -= 1;
		else
			env->main2 += 1;
		ft_menu(keycode, env, 2);
	}
	else if (c == 2 || c == 3)
		ft_menu2(keycode, env, c);
	else if (c == 4)
		ft_menu3(env);
	else if (c == 5)
	{
		env->main *= -1;
		env->main3 *= -1;
		ft_menu(keycode, env, 4);
	}
}

int			ft_zoom(t_env *env)
{
	int		i;
	double	tmp_z;

	i = 2;
	tmp_z = env->zoom;
	while (tmp_z > 100)
	{
		i++;
		tmp_z /= 10;
	}
	return (i);
}
