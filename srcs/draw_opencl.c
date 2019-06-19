/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/19 14:52:30 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			set_float_args(t_data *data)
{
	float			values[5];

	clSetKernelArg(data->opencl->kernel, 3, sizeof(int), &data->max_iteration);
	if (data->opencl->double_precision == 0)
	{
		values[0] = (float)data->zoom;
		values[1] = (float)data->move_x;
		values[2] = (float)data->move_y;
		values[3] = (float)data->fract->constants.r;
		values[4] = (float)data->fract->constants.i;
		clSetKernelArg(data->opencl->kernel, 4, sizeof(float), &values[0]);
		clSetKernelArg(data->opencl->kernel, 5, sizeof(float), &values[1]);
		clSetKernelArg(data->opencl->kernel, 6, sizeof(float), &values[2]);
		clSetKernelArg(data->opencl->kernel, 7, sizeof(float), &values[3]);
		clSetKernelArg(data->opencl->kernel, 8, sizeof(float), &values[4]);
		return ;
	}
	clSetKernelArg(data->opencl->kernel, 4, sizeof(double), &data->zoom);
	clSetKernelArg(data->opencl->kernel, 5, sizeof(double), &data->move_x);
	clSetKernelArg(data->opencl->kernel, 6, sizeof(double), &data->move_y);
	clSetKernelArg(data->opencl->kernel, 7, sizeof(double),
		&data->fract->constants.r);
	clSetKernelArg(data->opencl->kernel, 8, sizeof(double),
		&data->fract->constants.i);
}

void				draw_image_opencl(t_data *data)
{
	static int		colors_count = COLORS_COUNT;
	static size_t	dimensions[2] = { WIN_X, WIN_Y };

	clEnqueueWriteBuffer(data->opencl->command_queue,
		data->opencl->colors_buffer, CL_TRUE, 0, sizeof(int) * COLORS_COUNT,
		get_colors(data, FALSE), 0, NULL, NULL);
	clSetKernelArg(data->opencl->kernel, 0, sizeof(cl_mem),
		&data->opencl->pixels_buffer);
	clSetKernelArg(data->opencl->kernel, 1, sizeof(int), &dimensions[1]);
	clSetKernelArg(data->opencl->kernel, 2, sizeof(int), &dimensions[0]);
	set_float_args(data);
	clSetKernelArg(data->opencl->kernel, 9, sizeof(int), &colors_count);
	clSetKernelArg(data->opencl->kernel, 10, sizeof(cl_mem),
		&data->opencl->colors_buffer);
	clSetKernelArg(data->opencl->kernel, 11, sizeof(cl_mem),
		&data->opencl->iterations_buffer);
	clEnqueueNDRangeKernel(data->opencl->command_queue, data->opencl->kernel,
		2, NULL, dimensions, NULL, 0, NULL, NULL);
	clFinish(data->opencl->command_queue);
	clEnqueueReadBuffer(data->opencl->command_queue,
		data->opencl->pixels_buffer, CL_TRUE, 0, WIN_X * WIN_Y * sizeof(int),
		data->pixels, 0, NULL, NULL);
	clEnqueueReadBuffer(data->opencl->command_queue,
		data->opencl->iterations_buffer, CL_TRUE, 0, WIN_X * WIN_Y
		* sizeof(int), data->iterations_array, 0, NULL, NULL);
}
