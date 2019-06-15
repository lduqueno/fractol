/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:32:54 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/15 15:56:15 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

/*
**	Init all the fractals
*/

t_fract		*init_fractals(void)
{
	static	t_fract		fractals[FRACTAL_COUNT];

	fractals[0] = (t_fract) { .name = "julia", (t_complex){ .r = JULIA_CST_R,
		.i = JULIA_CST_I },  .max_iteration = 75, .execute = execute_julia };
	fractals[1] = (t_fract) { .name = "mandelbrot", .max_iteration = 75,
		.execute = execute_mandelbrot };
	fractals[2] = (t_fract) { .name = "burningship", .max_iteration = 75,
		.execute = execute_burningship };
	fractals[3] = (t_fract) { .name = "tricorn", .max_iteration = 75,
		.execute = execute_tricorn };
	fractals[4] = (t_fract) { .name = "eye", .max_iteration = 45,
		.execute = execute_eye };
	fractals[5] = (t_fract) { .name = "newton", .max_iteration = 60,
		.execute = execute_newton };
	fractals[6] = (t_fract) { .name = "nova", .max_iteration = 45,
		.execute = execute_nova };
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
