/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:32:54 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/13 17:51:17 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Init all the fractals
*/

t_fract		*init_fractals(void)
{
	static	t_fract		fractals[FRACTAL_COUNT];

	fractals[0] = (t_fract) { .name = "julia", .max_iteration = 200,
		(t_complex) {.r = -0.7, .i = 0.27015}, .execute = execute_julia };
	fractals[1] = (t_fract) { .name = "mandelbrot", .max_iteration = 300,
		.execute = execute_mandelbrot };
	fractals[2] = (t_fract) { .name = "burningship", .max_iteration = 300,
		.execute = execute_burningship };
	return (fractals);
}

/*
**	Given a name, return the fract structure which correponds
*/

t_fract		*get_fractal_by_name(t_fract *fractals, char *name)
{
	int		i;

	i = 0;
	while (i < FRACTAL_COUNT)
	{
		if (ft_strequignorecase(fractals[i].name, name))
			return (&fractals[i]);
		i++;
	}
	return (NULL);
}
