/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:40:20 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/13 18:30:42 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				execute_burningship(t_data *data, int y, int x)
{
	int			iteration;
	t_complex	complex;
	t_complex	tmp_pow;

	iteration = 0;
	complex.r = 1.5 * (x - WIN_X / 2) / (0.5 * data->zoom * WIN_X)
		+ data->move_x;
	complex.i = (y - WIN_Y / 2) / (0.5 * data->zoom * WIN_Y) + data->move_y;
	tmp_pow.r = complex.r * complex.r;
	tmp_pow.i = complex.i * complex.i;
	while (iteration < data->max_iteration)
	{
		complex.i = fabs(2 * complex.r * complex.i) + y;
		complex.r = fabs(tmp_pow.r - tmp_pow.i + x);
		tmp_pow.r = complex.r * complex.r;
		tmp_pow.i = complex.i * complex.i;
		if (tmp_pow.r + tmp_pow.i >= 4)
			break ;
		iteration++;
	}
	return (iteration);
}
