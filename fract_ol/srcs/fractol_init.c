/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:43:49 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/15 11:21:12 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fract_new_image(t_env *env)
{
	int		e;

	mlx_clear_window(env->mlx, env->win);
	if (!(env->img = mlx_new_image(env->mlx, MAX_X, MAX_Y)))
		ft_error("Problem of Mlx New Image 1");
	env->data = mlx_get_data_addr(env->img, &env->b, &env->l, &e);
	if (env->data == NULL)
		ft_error("Problem of Get_Data Image 1");
	env->b /= 8;
	if (!(env->img_2 = mlx_new_image(env->mlx, MAX_X, 200)))
		ft_error("Problem of Mlx New Image 2");
	env->data_2 = mlx_get_data_addr(env->img_2, &env->b_2, &env->l_2, &e);
	if (env->data == NULL)
		ft_error("Problem of Get_Data Image 2");
}

void		fractol_init_var(t_env *env)
{
	env->lock = 1;
	env->zoom = 100;
	env->ox = -(MAX_X / 2);
	env->oy = -(MAX_Y / 2);
	env->xx = env->ox;
	env->yy = env->oy;
	env->zi = 0;
	env->cr = 0.285;
	env->ci = 0.01;
	env->nb_zoom = 0;
	env->save_x_m = (MAX_X / 2);
	env->save_y_m = (MAX_Y / 2);
	env->i_max = 50;
}

void		ft_init_info(t_env *env)
{
	env->i = 1;
	env->mod_i = 1;
	env->main = 1;
	env->main2 = 1;
	env->main3 = 1;
	env->main4 = 1;
	env->info = -1;
	env->mod_j = 1;
	env->key_m = 1;
	env->key_h = 1;
	env->key_v = 1;
	env->save_x = -(MAX_X / 2);
	env->save_y = -(MAX_Y / 2);
	env->k = 0;
}

void		fract_init(t_env *env)
{
	ft_init_info(env);
	fractol_init_var(env);
	if (!(env->mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(env->win = mlx_new_window(env->mlx, MAX_X, MAX_Y + 200, NAME)))
		ft_error("mlx_new_windows error");
}
