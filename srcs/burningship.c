/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:40:20 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/18 19:55:45 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int				execute_burningship(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		complex;
	t_complex		constants;
	t_complex		tmp_pow;

	iteration = 0;
	complex.r = 1.5 * (x - WIN_X / 2) / (0.45 * data->zoom * WIN_X)
		+ data->move_x - 0.4;
	complex.i = 1.5 * (y - WIN_Y / 2) / (0.45 * data->zoom * WIN_Y)
		+ data->move_y - 0.5;
	constants.r = complex.r;
	constants.i = complex.i;
	tmp_pow.r = complex.r * complex.r;
	tmp_pow.i = complex.i * complex.i;
	while (iteration < data->max_iteration && tmp_pow.r + tmp_pow.i < 4)
	{
		complex.i = fabs(2 * complex.r * complex.i) + constants.i;
		complex.r = fabs(tmp_pow.r - tmp_pow.i + constants.r);
		tmp_pow.r = complex.r * complex.r;
		tmp_pow.i = complex.i * complex.i;
		iteration++;
	}
	return (iteration);
}
