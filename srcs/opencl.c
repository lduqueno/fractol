/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/15 20:20:23 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void			create_context(t_opencl *cl, char *function_name)
{
	cl_int			ret;

	ret = clGetPlatformIDs(1, &cl->platform_id, &cl->ret_num_platforms);
	ret = clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		&cl->device_id, &cl->ret_num_devices);
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &ret);
	cl->command_queue = clCreateCommandQueue(cl->context,
		cl->device_id, 0, &ret);
	cl->program = clCreateProgramWithSource(cl->context, 1,
		(const char **)&cl->source_str, (const size_t *)&cl->source_size, &ret);
	ret = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);
	cl->kernel = clCreateKernel(cl->program, function_name, &ret);
}

void				init_opencl(t_data *data)
{
	t_opencl		*cl;
	int				fd;
	char			*file_name;

	if (!(cl = (t_opencl *)malloc(sizeof(t_opencl))) || !(file_name
		= ft_strjoin("opencl/", data->fract->name)) || !(file_name
		= ft_strjoin_free(file_name, ".cl")))
			error(data, MALLOC_ERROR);
	cl->device_id = NULL;
	cl->context = NULL;
	cl->command_queue = NULL;
	cl->program = NULL;
	cl->kernel = NULL;
	cl->platform_id = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(data, OPEN_ERROR);
	if (!(cl->source_str = ft_strnew(MAX_SOURCE_SIZE)))
		error(data, MALLOC_ERROR);
	if ((cl->source_size = read(fd, cl->source_str, MAX_SOURCE_SIZE)) <= 0)
		error(data, READ_ERROR);
	close(fd);
	data->opencl = cl;
}

void				new_opencl_task(t_data *data)
{
	size_t			dimensions[2] = { WIN_X, WIN_Y };
	cl_mem			input_data;
	cl_mem			output;
	float			raw_data[DATA_COUNT] = { WIN_Y, WIN_X, data->max_iteration,
						data->zoom, data->move_x, data->move_y };

	create_context(data->opencl, data->fract->name);
	output = clCreateBuffer(data->opencl->context, CL_MEM_READ_WRITE,
		MEM_SIZE * sizeof(int), NULL, NULL);
	input_data = clCreateBuffer(data->opencl->context, CL_MEM_READ_ONLY,
		sizeof(float) * DATA_COUNT, NULL, NULL);
	clEnqueueWriteBuffer(data->opencl->command_queue, input_data, CL_TRUE, 0,
		sizeof(float) * DATA_COUNT, raw_data, 0, NULL, NULL);
	clSetKernelArg(data->opencl->kernel, 0, sizeof(cl_mem),
		(void *)&output);
	clSetKernelArg(data->opencl->kernel, 1, sizeof(cl_mem),
		(void *)&input_data);

	//clEnqueueTask(data->opencl->command_queue, data->opencl->kernel, 0, NULL, NULL);
	clEnqueueNDRangeKernel(data->opencl->command_queue, data->opencl->kernel,
		2, NULL, dimensions, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(data->opencl->command_queue, output,
		CL_TRUE, 0, MEM_SIZE * sizeof(int), data->pixels, 0, NULL, NULL);
	clReleaseMemObject(input_data);
	clReleaseMemObject(output);
	close_opencl(data->opencl, FALSE);
}

void				close_opencl(t_opencl *cl, t_bool free_program)
{
	clFlush(cl->command_queue);
	clFinish(cl->command_queue);
	clReleaseKernel(cl->kernel);
	clReleaseProgram(cl->program);
	clReleaseCommandQueue(cl->command_queue);
	clReleaseContext(cl->context);
	if (free_program)
		free(cl->source_str);
}
