/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:22:36 by grdalmas          #+#    #+#             */
/*   Updated: 2018/07/10 14:58:28 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			julia(t_env *env, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (env->i_max == 0)
		return (0);
	env->zr = env->x / env->zoom + env->xx / env->zoom;
	env->zi = env->y / env->zoom + env->yy / env->zoom;
	zr = env->zr * env->zr;
	zi = env->zi * env->zi;
	while ((zr + zi) < 4 && ++i < env->i_max)
	{
		tmp = env->zr;
		env->zr = zr - zi + env->cr;
		env->zi = 2 * env->zi * tmp + env->ci;
		zr = env->zr * env->zr;
		zi = env->zi * env->zi;
	}
	return (i);
}

int			mandelbrot(t_env *env, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (env->i_max == 0)
		return (0);
	env->cr = env->x / env->zoom + env->xx / env->zoom;
	env->ci = env->y / env->zoom + env->yy / env->zoom;
	zr = env->zr * env->zr;
	zi = env->zi * env->zi;
	while ((zr + zi) < 4 && ++i < env->i_max)
	{
		tmp = env->zr;
		env->zr = zr - zi + env->cr;
		env->zi = 2 * env->zi * tmp + env->ci;
		zr = env->zr * env->zr;
		zi = env->zi * env->zi;
	}
	return (i);
}

int			mandelbar(t_env *env, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (env->i_max == 0)
		return (0);
	env->cr = env->x / env->zoom + env->xx / env->zoom;
	env->ci = env->y / env->zoom + env->yy / env->zoom;
	zr = env->zr * env->zr * 2;
	zi = env->zi * env->zi * 2;
	while ((zr + zi) < 4 && ++i < env->i_max)
	{
		tmp = env->zr;
		env->zr = zr - zi - env->cr;
		env->zi = -2 * env->zi * tmp + env->ci;
		zr = env->zr * env->zr;
		zi = env->zi * env->zi;
	}
	return (i);
}

int			celtic(t_env *env, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	env->cr = env->x / env->zoom + env->xx / env->zoom;
	env->ci = env->y / env->zoom + env->yy / env->zoom;
	zr = env->zr * env->zr * 2;
	zi = env->zi * env->zi * 2;
	while ((zr + zi) < 4 && ++i < env->i_max)
	{
		tmp = env->zr;
		env->zr = fabs(zr - zi) + env->cr;
		env->zi = 2 * env->zi * tmp + env->ci;
		zr = env->zr * env->zr;
		zi = env->zi * env->zi;
	}
	return (i);
}

int			burning_ship(t_env *env, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	env->cr = env->x / env->zoom + env->xx / env->zoom;
	env->ci = env->y / env->zoom + env->yy / env->zoom;
	zr = env->zr * env->zr * 2;
	zi = env->zi * env->zi * 2;
	while ((zr + zi) < 4 && ++i < env->i_max)
	{
		tmp = env->zr;
		env->zr = zr - zi - env->cr;
		env->zi = 2 * fabs(env->zi) * fabs(tmp) + env->ci;
		zr = env->zr * env->zr;
		zi = env->zi * env->zi;
	}
	return (i);
}
