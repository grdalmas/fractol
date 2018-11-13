/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:42:10 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 19:52:21 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				fract_key_menu(int k, t_env *env)
{
	if ((k == RIGHT || k == LEFT) && env->main == -1 && env->main2 == 1)
	{
		if (k == LEFT)
		{
			env->main3 = 1;
			ft_menu(k, env, 2);
		}
		else if (k == RIGHT)
		{
			env->main3 = -1;
			ft_menu(k, env, 4);
		}
	}
	else if (env->main == -1 && (k == UP || k == DOWN) && env->main3 == 1)
		ft_menu(k, env, 1);
	else if (env->main == -1 && (k == ENTER) && env->main3 == 1)
		ft_menu(k, env, 2);
	else if ((k == DOWN || k == UP) && env->main3 == -1)
	{
		ft_menu(k, env, 3);
		ft_menu(k, env, 4);
		fractal_print(env);
	}
	else if (env->main == -1 && env->main3 == -1 && (k == ENTER))
		ft_menu(k, env, 5);
}

void				fract_key_move(int k, t_env *env)
{
	if (env->main == 1 && (k == LEFT || k == RIGHT))
		env->xx -= (k == LEFT) ? 30 : -30;
	else if (env->main == 1 && (k == UP || k == DOWN))
		env->yy -= (k == UP) ? 30 : -30;
	else if (env->mod_i == -1 && k == PLUS && env->i_max < 0)
		env->i_max = 0;
	else if (env->mod_i == 1 && env->main == 1 && (k == PLUS || k == MINUS))
	{
		env->zoom *= (k == PLUS) ? 2 : 0.5;
		env->nb_zoom += (k == PLUS) ? 2 : -2;
	}
	else if (env->mod_i == -1 && env->main == 1 && k == PLUS)
		env->i_max += 1;
	if (k == O)
		fractol_init_var(env);
}

void				frat_key_2(int k, t_env *env)
{
	fract_key_menu(k, env);
	fract_key_move(k, env);
	if (k == I)
		env->i *= -1;
	else if (k == M)
		env->key_m *= -1;
	else if (k == H)
		env->key_h *= -1;
	else if (k == V)
		env->key_v *= -1;
}

int					fract_key(int k, t_env *env)
{
	frat_key_2(k, env);
	if (k == J && env->mod_j == 1)
		env->mod_j += -2;
	else if (k == J && env->mod_j == -1)
		env->mod_j += -1;
	else if (k == J && env->mod_j == -2)
		env->mod_j = 1;
	else if (k == KEY_1 || k == KEY_2)
		env->k = (k == KEY_1) ? KEY_1 : KEY_2;
	else if (k == KEY_3 || k == KEY_4)
		env->k = (k == KEY_3) ? KEY_3 : KEY_4;
	else if (k == ESC)
		ft_error("See you space clodo!!");
	else if (k == I)
		(k == I) ? (env->mod_i *= -1) : (env->info_i *= -1);
	else if (env->mod_i == -1 && env->main == 1 && k == MINUS && env->i_max
				>= 1)
		(env->i_max == 0) ? (env->i_max = 0) : (env->i_max -= 1);
	fractal_print(env);
	return (0);
}
