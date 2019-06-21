/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_nova.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/21 09:59:02 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

/*
**	Nova fractal
*/

int				execute_nova(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		c;
	t_complex		half;

	iteration = 0;
	c.r = 1.5 * (x - WIN_X / 2) / (0.5 * data->zoom * WIN_X)
		+ data->move_x;
	c.i = 1.5 * (y - WIN_Y / 2) / (0.5 * data->zoom * WIN_Y)
		+ data->move_y;
	half.r = 1.2;
	half.i = 0.0;
	while (iteration < data->max_iteration)
	{
		if (c.r * c.r + c.i * c.i >= 8)
			break ;
		c = zadd(zmultiply(c, zsubtract(c, zpow(c, 3))), half);
		iteration++;
	}
	return (iteration);
}
