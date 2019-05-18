/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/18 11:48:49 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			print_log(t_data *data)
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
	ft_dprintf(STDERR_FILENO, "Unable to compile .cl file!");
	ft_dprintf(STDERR_FILENO, "Build log: \n%s\n", buff_erro);
	free(buff_erro);
	error(data, OPENCL_LOG_ERROR);
}

static void			create_opencl_context(t_data *data)
{
	t_opencl	*cl;
	cl_int		ret;
	char		*function_name;

	cl = data->opencl;
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret);
	cl->command_queue = clCreateCommandQueue(cl->context,
		cl->device_id, 0, &ret);
	cl->program = clCreateProgramWithSource(cl->context, 1,
		(const char **)&cl->source_str, (const size_t *)&cl->source_size, &ret);
	ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);
	if (ret != CL_SUCCESS)
	{
		print_log(data);
		error(data, OPENCL_ERROR);
	}
	if (!(function_name = ft_strjoin(data->fract->name,
			cl->double_precision_supported ? "_double" : "_float")))
		error(data, MALLOC_ERROR);
	cl->kernel = clCreateKernel(cl->program, function_name, &ret);
	free(function_name);
}

static cl_mem		get_data_arg(t_data *data)
{
	float		float_data[DATA_COUNT] = { WIN_Y, WIN_X, data->max_iteration,
		data->zoom, data->move_x, data->move_y, COLORS_COUNT };
	double		double_data[DATA_COUNT] = { WIN_Y, WIN_X, data->max_iteration,
		data->zoom, data->move_x, data->move_y, COLORS_COUNT };
	cl_mem		result;

	if (data->opencl->double_precision_supported == 0)
	{
		result = clCreateBuffer(data->opencl->context, CL_MEM_READ_ONLY,
			sizeof(float) * DATA_COUNT, NULL, NULL);
		clEnqueueWriteBuffer(data->opencl->command_queue, result, CL_TRUE, 0,
			sizeof(float) * DATA_COUNT, float_data, 0, NULL, NULL);
	}
	else
	{
		result = clCreateBuffer(data->opencl->context, CL_MEM_READ_ONLY,
			sizeof(double) * DATA_COUNT, NULL, NULL);
		clEnqueueWriteBuffer(data->opencl->command_queue, result, CL_TRUE, 0,
			sizeof(double) * DATA_COUNT, double_data, 0, NULL, NULL);
	}
	return (result);
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
	if (!(file_name = ft_strjoin("opencl/",
			cl->double_precision_supported ? "double/" : "float/"))
			|| !(file_name = ft_strjoin_free(file_name, data->fract->name))
			|| !(file_name = ft_strjoin_free(file_name, ".cl")))
		error(data, MALLOC_ERROR);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(data, OPEN_ERROR);
	if (!(cl->source_str = ft_strnew(MAX_SOURCE_SIZE)))
		error(data, MALLOC_ERROR);
	if ((cl->source_size = read(fd, cl->source_str, MAX_SOURCE_SIZE)) <= 0)
		error(data, READ_ERROR);
	close(fd);
	data->opencl = cl;
}

void				draw_image_opencl(t_data *data)
{
	size_t		dimensions[2] = { WIN_X, WIN_Y };
	cl_mem		pixels;
	cl_mem		input_data;
	cl_mem		colors_data;

	create_opencl_context(data);
	pixels = clCreateBuffer(data->opencl->context, CL_MEM_READ_WRITE,
		MEM_SIZE * sizeof(int), NULL, NULL);
	input_data = get_data_arg(data);
	colors_data = clCreateBuffer(data->opencl->context, CL_MEM_READ_ONLY,
		sizeof(int) * COLORS_COUNT, NULL, NULL);
	clEnqueueWriteBuffer(data->opencl->command_queue, colors_data, CL_TRUE, 0,
		sizeof(int) * COLORS_COUNT, get_colors(), 0, NULL, NULL);
	clSetKernelArg(data->opencl->kernel, 0, sizeof(cl_mem), &pixels);
	clSetKernelArg(data->opencl->kernel, 1, sizeof(cl_mem), &input_data);
	clSetKernelArg(data->opencl->kernel, 2, sizeof(cl_mem), &colors_data);
	clEnqueueNDRangeKernel(data->opencl->command_queue, data->opencl->kernel,
		2, NULL, dimensions, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(data->opencl->command_queue, pixels,
		CL_TRUE, 0, MEM_SIZE * sizeof(int), data->pixels, 0, NULL, NULL);
	clReleaseMemObject(pixels);
	clReleaseMemObject(input_data);
	clReleaseMemObject(colors_data);
	close_opencl(data->opencl);
}
