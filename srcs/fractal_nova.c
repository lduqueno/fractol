/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_nova.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/14 16:28:35 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int				execute_nova(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		c;
	t_complex		two;

	iteration = 0;
	c.r = 1.5 * (x - WIN_X / 2) / (0.1 * data->zoom * WIN_X)
		+ data->move_x - 0.7;
	c.i = 1.5 * (y - WIN_Y / 2) / (0.1 * data->zoom * WIN_Y)
		+ data->move_y;
	two.r = 2.0;
	two.i = 0.0;
	while (iteration < data->max_iteration)
	{
		if (c.r * c.r + c.i * c.i > 48)
			break ;
		c = zpow(zdivide(zpow(c, 2), (zsubtract(zmultiply(c, two), two))), 2);
		iteration++;

		// a faire :
		cfloat c = (cfloat)(1.5 * (x - win_width / 2) / (0.5 * zoom * win_width) + 2 * move_x,
			1.5 * (y - win_height / 2) / (0.5 * zoom * win_height) + 2 * move_y);
		int pixel_id = y * win_width + x;
		cfloat three = (cfloat)(.5, 0.0);

		while (iteration < max_iteration)
		{
			if (c.x * c.x + c.y * c.y >= 8)
				break ;
			c = zmult(c, zsubtract(c, zpow(c, 3))) + three;
			iteration++;
		}
	}
	return (iteration);
}
