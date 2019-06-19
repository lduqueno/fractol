/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_flower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/19 14:54:34 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int				execute_flower(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		c;
	t_complex		add;

	iteration = 0;
	c.r = 1.5 * (x - WIN_X / 2) / (0.31 * data->zoom * WIN_X)
		+ 3 * data->move_x;
	c.i = 1.5 * (y - WIN_Y / 2) / (0.31 * data->zoom * WIN_Y)
		+ 3 * data->move_y;
	add.r = 0.9;
	add.i = 0.0;
	while (iteration < data->max_iteration)
	{
		if (c.r * c.r + c.i * c.i >= 8)
			break ;
		c = zsubtract(zpow(zdivide(c, zpow(c, 3)), 4), add);
		iteration++;
	}
	return (iteration);
}
