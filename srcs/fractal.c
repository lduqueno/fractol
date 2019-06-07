/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:32:54 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 17:56:18 by lduqueno         ###   ########.fr       */
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
		.i = JULIA_CST_I }, .execute = execute_julia };
	fractals[1] = (t_fract) { .name = "mandelbrot",
		.execute = execute_mandelbrot };
	fractals[2] = (t_fract) { .name = "burningship",
		.execute = execute_burningship };
	fractals[3] = (t_fract) { .name = "tricorn",
		.execute = execute_tricorn };
	fractals[4] = (t_fract) { .name = "flower",
		.execute = execute_flower };
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
