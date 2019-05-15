/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:15:55 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/15 19:54:56 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				execute_mandelbrot(t_data *data, int y, int x)
{
	int			iteration;
	t_complex	complex;
	t_complex	tmp_pow;
	t_complex	constants;

	iteration = 0;
	constants.r = 1.0 * (x - WIN_X / 2) / (0.5 * data->zoom * WIN_X)
		+ data->move_x - 0.4;
	constants.i = (y - WIN_Y / 2) / (0.5 * data->zoom * WIN_Y) + data->move_y;
	complex.r = 0;
	complex.i = 0;
	tmp_pow.r = complex.r * complex.r;
	tmp_pow.i = complex.i * complex.i;
	while (iteration < data->max_iteration)
	{
		complex.i = 2 * complex.r * complex.i + constants.i;
		complex.r = tmp_pow.r - tmp_pow.i + constants.r;
		tmp_pow.r = complex.r * complex.r;
		tmp_pow.i = complex.i * complex.i;
		if (tmp_pow.r + tmp_pow.i >= 4)
			break ;
		iteration++;
	}
	return (iteration);
}

/*
int iteration = 0;
int x = get_global_id(0);
int y = get_global_id(1);
int win_height = convert_int(data[0]);
int win_width = convert_int(data[1]);
int max_iteration = convert_int(data[2]);
float zoom = data[3];
float move_x = data[4];
float move_y = data[5];
float cRe = 1.5 * (x - win_width / 2) / (0.5 * zoom * win_width) + move_x;
float cIm = (y - win_height / 2) / (0.5 * zoom * win_height) + move_y;
float powRe = cRe * cRe;
float powIm = cIm * cIm;

while (iteration < max_iteration && powRe + powIm < 4)
{
	cIm = 2 * cRe * cIm + 0.27015;
	cRe = powRe - powIm + -0.7;
	powRe = cRe * cRe;
	powIm = cIm * cIm;
	iteration++;
}
if (iteration == max_iteration)
	pixels[y * win_width + x] = 0x00000;
else
	pixels[y * win_width + x] = (0xFFFFFF / max_iteration * iteration / 10);
	*/
