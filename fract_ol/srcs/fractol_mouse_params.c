/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:02:51 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 18:23:57 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_resize(t_env *env, int x, int y, char c)
{
	env->xx *= -1;
	env->yy *= -1;
	env->tmp_z = env->zoom;
	if (c == '*')
		env->zoom *= 2;
	else if (c == '/')
		env->zoom /= 2;
	env->nb_zoom += (c == '*') ? 2 : -2;
	if (x <= env->xx)
		env->tmp_x = -(env->xx - x);
	if (x > env->xx)
		env->tmp_x = x - env->xx;
	if (y <= env->yy)
		env->tmp_y = env->yy - y;
	if (y > env->yy)
		env->tmp_y = -(y - env->yy);
	env->tmp_xx = ((env->zoom * env->tmp_x) / env->tmp_z);
	env->tmp_yy = ((env->zoom * env->tmp_y) / env->tmp_z);
	env->xx -= env->tmp_xx - env->tmp_x;
	env->yy += env->tmp_yy - env->tmp_y;
	env->xx *= -1;
	env->yy *= -1;
}

int				ft_key_mouse(int k, int x, int y, t_env *env)
{
	if (k == M_LEFT && (x >= 520 && y > MAX_Y))
		env->main *= -1;
	if (env->mod_i == -1 && k == M_PLUS && env->mod_i != -1)
		env->i_max += 1;
	if ((x >= 0 && x <= MAX_X) && (y >= 0 && y <= MAX_Y))
	{
		if (env->mod_i == 1 && k == M_PLUS && env->mod_i != -1)
			ft_resize(env, x, y, '*');
		if (env->mod_i == 1 && k == M_MINUS && env->mod_i != -1)
			ft_resize(env, x, y, '/');
		if (k == M_LEFT)
			ft_resize(env, x, y, '*');
		if (k == M_RIGHT)
			ft_resize(env, x, y, '/');
		if (k == ELEVEN)
			env->mod_i *= -1;
		if (env->mod_i == -1 && (k == M_PLUS || k == M_MINUS))
			env->i_max += (k == M_PLUS) ? 1 : -1;
		if (env->mod_i == -1 && k == M_MINUS)
			env->i_max -= (env->i_max) ? 0 : 1;
	}
	if (env->i_max < 0)
		env->i_max = 0;
	fractal_print(env);
	return (0);
}

void			move_to_mouse(t_env *env, int x, int y, int c)
{
	if ((x >= 0 && x <= MAX_X) && (y >= 0 && y <= MAX_Y))
	{
		if (c == 1)
		{
			if (x <= env->save_x_m)
				env->xx += 30;
			else if (x > env->save_x_m)
				env->xx -= 30;
			env->save_x_m = x;
		}
		else if (c == 2)
		{
			if (y <= env->save_y_m)
				env->yy += 30;
			else if (y >= env->save_y_m)
				env->yy -= 30;
			env->save_y_m = y;
		}
	}
}

void			main_menu_intera(t_env *env, int x, int y)
{
	if (x >= 524 && x <= MAX_X && y >= 606 && y <= MAX_Y + 200)
	{
		if (x >= 548 && x <= 707 && y >= 623 && y <= 644)
			env->main2 = 1;
		else if (x >= 550 && x <= 754 && y >= 656 && y <= 670)
			env->main2 = 2;
		else if (x >= 550 && x <= 745 && y >= 686 && y <= 700)
			env->main2 = 3;
		else if (x >= 550 && x <= 780 && y >= 715 && y <= 731)
			env->main2 = 4;
		else if (x >= 550 && x <= 715 && y >= 744 && y <= 763)
			env->main2 = 5;
		ft_menu(0, env, 2);
	}
}

int				mouse_position(int x, int y, t_env *env)
{
	if (env->key_h == 1)
		env->save_x_m = x;
	if (env->key_v == 1)
		env->save_y_m = y;
	if (env->mod_j == -1 && env->key_m == 1)
		env->cr += (env->save_x >= x) ? (-0.02) : 0.02;
	if (env->mod_j == -2 && env->key_m == 1)
		env->ci += (env->save_x >= x) ? (-0.02) : 0.02;
	if (env->key_m == -1)
	{
		env->xx = -x;
		env->yy = -y;
	}
	if (env->key_h == -1)
		move_to_mouse(env, x, y, 1);
	if (env->key_v == -1)
		move_to_mouse(env, x, y, 2);
	if (env->main == -1)
		main_menu_intera(env, x, y);
	env->save_x = x;
	fractal_print(env);
	return (0);
}
