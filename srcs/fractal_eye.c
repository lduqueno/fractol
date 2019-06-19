/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_eye.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/19 14:54:24 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int				execute_eye(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		c;

	iteration = 0;
	c.r = (x - WIN_X / 2) / (0.2 * data->zoom * WIN_X) + 3 * data->move_x;
	c.i = (y - WIN_Y / 2) / (0.2 * data->zoom * WIN_Y) + 3 * data->move_y;
	while (iteration < data->max_iteration)
	{
		if (c.r * c.r + c.i * c.i >= 4 && sqrt(c.r * c.r + c.i * c.i) < 25)
			break ;
		c = zdivide(c, zsubtract(c, zpow(c, 3)));
		iteration++;
	}
	return (iteration);
}
