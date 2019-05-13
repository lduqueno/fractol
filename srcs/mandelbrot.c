/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/13 16:43:04 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				execute_mandelbrot(t_data *data, int y, int x)
{
	int			iteration;
	t_complex	complex;
	t_complex	tmp_pow;
	t_complex	constants;

	iteration = 0;
	constants.r = 1.0 * (x - WIN_X / 2) / (0.5 * data->zoom * WIN_X)
		+ data->move_x - 0.4;
	constants.i = (y - WIN_Y / 2) / (0.5 * data->zoom * WIN_Y) + data->move_y;
	complex.r = 0;
	complex.i = 0;
	tmp_pow.r = complex.r * complex.r;
	tmp_pow.i = complex.i * complex.i;
	while (iteration < data->fract->max_iteration)
	{
		complex.i = 2 * complex.r * complex.i + constants.i;
		complex.r = tmp_pow.r - tmp_pow.i + constants.r;
		tmp_pow.r = complex.r * complex.r;
		tmp_pow.i = complex.i * complex.i;
		if (tmp_pow.r + tmp_pow.i >= 4)
			break ;
		iteration++;
	}
	return (iteration);
}
