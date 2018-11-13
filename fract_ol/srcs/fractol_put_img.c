/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:13:47 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/14 19:51:51 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				choose_color(t_env *env)
{
	if (env->k == KEY_1)
		return (0x00FFFF);
	else if (env->k == KEY_2)
		return (0x6C0277);
	else if (env->k == KEY_3)
		return (0xFF358B);
	else if (env->k == KEY_4)
		return (0x96CA2D);
	return (0x00FFFF);
}

void			play_color(t_env *env, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = choose_color(env);
	color_front = choose_color(env);
	if (i == 0 || i == env->i_max)
	{
		env->data[k] = color_back;
		env->data[++k] = color_back >> 8;
		env->data[++k] = color_back >> 16;
	}
	else
	{
		env->data[k] = ((color_front / env->i_max) * i);
		env->data[++k] = ((color_front / env->i_max) * i) >> 8;
		env->data[++k] = ((color_front / env->i_max) * i) >> 16;
	}
}

void			fractal_print(t_env *env)
{
	int			i;

	mlx_clear_window(env->mlx, env->win);
	ft_bzero(env->data, (MAX_X * MAX_Y));
	env->y = -1;
	env->tmp_zi = env->zi;
	while (++env->y < MAX_Y)
	{
		env->x = -1;
		while (++env->x < MAX_X)
		{
			i = -1;
			env->zr = 0;
			env->zi = env->tmp_zi;
			i = env->ft(env, i);
			play_color(env, (env->x * 4 + env->y * MAX_X * 4), i);
		}
	}
	env->zi = env->tmp_zi;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->img_2, 0, MAX_Y);
	ft_print_info(env);
}
