/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print_menu_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:07:30 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 19:37:11 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_print_sub_menu(t_env *env)
{
	env->str = " *   Style 1";
	env->color = (env->main4 == 1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 810, 620, env->color, env->str);
	env->str = " *   Style 2";
	env->color = (env->main4 == 2) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 810, 650, env->color, env->str);
	env->str = " *   Style 3";
	env->color = (env->main4 == 3) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 810, 680, env->color, env->str);
	env->str = " *   Style 4";
	env->color = (env->main4 == 4) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 810, 710, env->color, env->str);
}

void			ft_print_menu(t_env *env)
{
	env->str = "-> Julia";
	env->color = (env->main2 == 1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 550, 620, env->color, env->str);
	env->str = "-> Mandelbrot";
	env->color = (env->main2 == 2) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 550, 650, env->color, env->str);
	env->str = "-> Mandelbar";
	env->color = (env->main2 == 3) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 550, 680, env->color, env->str);
	env->str = "-> Burning Ship";
	env->color = (env->main2 == 4) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 550, 710, env->color, env->str);
	env->str = "-> Celtic";
	env->color = (env->main2 == 5) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 550, 740, env->color, env->str);
}

void			ft_print_info_menu(t_env *env)
{
	env->str = "Info (Click to open fractals menu)";
	mlx_string_put(env->mlx, env->win, 480, 605, WHITE, env->str);
	env->str = "Press O to go back to origin			";
	mlx_string_put(env->mlx, env->win, 480, 630, WHITE, env->str);
	env->str = "Scroll Up or Dowm to Zoom/Unzoom   OR	";
	mlx_string_put(env->mlx, env->win, 480, 650, WHITE, env->str);
	env->str = "If no Mousewheel, Rick Click and Left Click";
	mlx_string_put(env->mlx, env->win, 480, 670, WHITE, env->str);
	env->str = "Press V for vertical mouse displacement	";
	mlx_string_put(env->mlx, env->win, 480, 690, WHITE, env->str);
	env->str = "Press H for horizontal mouse displacement";
	mlx_string_put(env->mlx, env->win, 480, 710, WHITE, env->str);
	env->str = "Press J to play with Julia    			";
	mlx_string_put(env->mlx, env->win, 480, 730, WHITE, env->str);
	env->str = "Press I and scroll to change iteration	";
	mlx_string_put(env->mlx, env->win, 480, 750, WHITE, env->str);
	env->str = "Press M to move it with mouse			";
	mlx_string_put(env->mlx, env->win, 480, 770, WHITE, env->str);
}
