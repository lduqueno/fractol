/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/19 14:50:08 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

static t_complex	f(t_complex c)
{
	t_complex		one;

	one.r = 1;
	one.i = 0;
	return (zsubtract(zpow(c, 3), one));
}

static t_complex	df(t_complex c)
{
	t_complex		three;

	three.r = 3;
	three.i = 0;
	return (zmultiply(zmultiply(c, c), three));
}

int					execute_newton(t_data *data, int y, int x)
{
	unsigned int	iteration;
	t_complex		c;
	t_complex		func;

	iteration = 0;
	c.r = (x - WIN_X / 2) / (0.01 * data->zoom * WIN_X) + 30 * data->move_x;
	c.i = (y - WIN_Y / 2) / (0.01 * data->zoom * WIN_Y) + 30 * data->move_y;
	while (iteration < data->max_iteration)
	{
		func = f(c);
		if (sqrt(func.r * func.r + func.i * func.i) < 0.0001)
			break ;
		c = zsubtract(c, zdivide(func, df(c)));
		iteration++;
	}
	return (iteration);
}
