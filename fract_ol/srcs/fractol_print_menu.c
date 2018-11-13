/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:33:31 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 19:54:06 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_print_info_3(t_env *env)
{
	if (env->main == -1)
	{
		ft_print_menu(env);
		if (env->main2 == 1 && env->main3 == -1)
			ft_print_sub_menu(env);
	}
	if (env->main == 1)
		ft_print_info_menu(env);
}

void		ft_print_info_2(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 670, WHITE, "Current Iter :");
	env->str = ft_itoa(env->i_max);
	mlx_string_put(env->mlx, env->win, 165, 670, 0x01B0F0, env->str);
	free(env->str);
	env->str = "Zoom Power 10*";
	mlx_string_put(env->mlx, env->win, 10, 690, WHITE, env->str);
	env->str = ft_itoa(ft_zoom(env));
	mlx_string_put(env->mlx, env->win, 163, 690, WHITE, env->str);
	free(env->str);
	env->str = "Mouse Horizontal Disp";
	mlx_string_put(env->mlx, env->win, 10, 710, WHITE, env->str);
	env->str = (env->key_h == -1) ? "On" : "Off";
	env->color = (env->key_h == -1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 255, 710, env->color, env->str);
	env->str = "Mouse Vertical Disp";
	mlx_string_put(env->mlx, env->win, 10, 730, WHITE, env->str);
	env->str = (env->key_v == -1) ? "On" : "Off";
	env->color = (env->key_v == -1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 255, 730, env->color, env->str);
}

void		ft_print_info(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 10, 610, WHITE, "Modify Iteration");
	env->str = (env->mod_i != 1) ? "On" : "Off";
	env->color = (env->mod_i != 1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 255, 610, env->color, env->str);
	mlx_string_put(env->mlx, env->win, 10, 630, WHITE, "Modify Julia");
	if (env->mod_j < 1)
		env->str = (env->mod_j == -1) ? "Cr" : "Ci";
	else
		env->str = "Off";
	env->color = (env->mod_j != 1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 255, 630, env->color, env->str);
	env->str = "Mouse Control";
	mlx_string_put(env->mlx, env->win, 10, 650, WHITE, env->str);
	env->str = (env->key_m == -1) ? "On" : "Off";
	env->color = (env->key_m == -1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 255, 650, env->color, env->str);
	ft_print_color_info(env);
	ft_print_info_2(env);
	ft_print_info_3(env);
}

void		ft_print_color_info(t_env *env)
{
	env->str = "Color Options :";
	mlx_string_put(env->mlx, env->win, 320, 610, WHITE, env->str);
	env->color = (env->k == 0 || env->k == KEY_1) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 320, 660, env->color, "Start   -> 1 ");
	env->color = (env->k == KEY_2) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 320, 690, env->color, "Color 2 -> 2 ");
	env->color = (env->k == KEY_3) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 320, 720, env->color, "Color 3 -> 3 ");
	env->color = (env->k == KEY_4) ? 0x01B0F0 : WHITE;
	mlx_string_put(env->mlx, env->win, 320, 750, env->color, "Color 4 -> 4 ");
}
