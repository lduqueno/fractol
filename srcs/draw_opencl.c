/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 17:54:09 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"

static void			print_error_log(t_data *data)
{
	char		*buff_erro;
	cl_int		ret;
	size_t		build_log_len;

	ret = clGetProgramBuildInfo(data->opencl->program, data->opencl->device_id,
		CL_PROGRAM_BUILD_LOG, 0, NULL, &build_log_len);
	if (ret)
		error(data, OPENCL_LOG_ERROR);
	if (!(buff_erro = (char *)malloc(sizeof(char) * build_log_len)))
		error(data, MALLOC_ERROR);
	ret = clGetProgramBuildInfo(data->opencl->program, data->opencl->device_id,
		CL_PROGRAM_BUILD_LOG, build_log_len, buff_erro, NULL);
	if (ret)
		error(data, OPENCL_LOG_ERROR);
	ft_dprintf(STDERR_FILENO, "Build log: \n%s\n", buff_erro);
	error(data, OPENCL_ERROR);
}

static void			init_opencl_next(t_data *data)
{
	t_opencl	*cl;
	cl_int		ret;

	cl = data->opencl;
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret);
	cl->command_queue = clCreateCommandQueue(cl->context,
		cl->device_id, 0, &ret);
	cl->program = clCreateProgramWithSource(cl->context, 1,
		(const char **)&cl->source_str, (const size_t *)&cl->source_size, &ret);
	ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);
	if (ret != CL_SUCCESS)
		print_error_log(data);
	cl->kernel = clCreateKernel(cl->program, data->fract->name, &ret);
	data->opencl->pixels_buffer = clCreateBuffer(data->opencl->context,
		CL_MEM_READ_WRITE, WIN_X * WIN_Y * sizeof(int), NULL, NULL);
	data->opencl->colors_buffer = clCreateBuffer(data->opencl->context,
		CL_MEM_READ_ONLY, sizeof(int) * COLORS_COUNT, NULL, NULL);
	data->opencl->iterations_buffer = clCreateBuffer(data->opencl->context,
		CL_MEM_READ_WRITE, WIN_X * WIN_Y * sizeof(int), NULL, NULL);
}

static void			set_float_args(t_data *data)
{
	float			values[5];

	clSetKernelArg(data->opencl->kernel, 3, sizeof(int), &data->max_iteration);
	if (data->opencl->double_precision_supported == 0)
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
		get_colors(FALSE), 0, NULL, NULL);
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

void				init_opencl(t_data *data)
{
	t_opencl	*cl;
	int			fd;
	char		*file_name;

	if (!(cl = (t_opencl *)malloc(sizeof(t_opencl))))
		error(data, MALLOC_ERROR);
	clGetPlatformIDs(1, &cl->platform_id, &cl->ret_num_platforms);
	clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		&cl->device_id, &cl->ret_num_devices);
	clGetDeviceInfo(cl->device_id, CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE,
		sizeof(cl_uint), &cl->double_precision_supported, NULL);
	if (!(file_name = ft_strjoin("opencl/", data->fract->name))
			|| !(file_name = ft_strjoin_free(file_name, ".cl"))
			|| !(cl->source_str = ft_strnew(MAX_SOURCE_SIZE)))
		error(data, MALLOC_ERROR);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(data, OPEN_ERROR);
	free(file_name);
	if ((cl->source_size = read(fd, cl->source_str, MAX_SOURCE_SIZE)) <= 0)
		error(data, READ_ERROR);
	if (cl->double_precision_supported == 0)
		ft_strreplace(cl->source_str, "double", "float");
	close(fd);
	data->opencl = cl;
	init_opencl_next(data);
}
