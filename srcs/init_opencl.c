/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:51:58 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/14 11:31:18 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "ft_printf.h"

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

static void			open_file(t_data *data)
{
	char		*file_name;
	int			fd;


	if (!(file_name = ft_strjoin("opencl/", data->fract->name))
			|| !(file_name = ft_strjoin_free(file_name, ".cl"))
			|| !(data->opencl->source_str = ft_strnew(MAX_SOURCE_SIZE)))
		error(data, MALLOC_ERROR);

	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(data, OPEN_ERROR);
	free(file_name);
	if ((data->opencl->source_size = read(fd, data->opencl->source_str,
					MAX_SOURCE_SIZE)) <= 0)
		error(data, READ_ERROR);
	close(fd);
}

void				init_opencl(t_data *data, t_bool use_float)
{
	if (!(data->opencl = (t_opencl *)malloc(sizeof(t_opencl))))
		error(data, MALLOC_ERROR);
	clGetPlatformIDs(1, &data->opencl->platform_id,
		&data->opencl->ret_num_platforms);
	clGetDeviceIDs(data->opencl->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		&data->opencl->device_id, &data->opencl->ret_num_devices);
	clGetDeviceInfo(data->opencl->device_id,
		CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE, sizeof(cl_uint),
		&data->opencl->double_precision, NULL);
	if (data->opencl->double_precision && use_float)
		data->opencl->double_precision = 0;
	else if (!data->opencl->double_precision)
		ft_printf("Double precision is NOT supported on this device.\nThe "
			"quality of the fractal may decrease a lot.\n");
	open_file(data);
	if (data->opencl->double_precision == 0)
		ft_strreplace(data->opencl->source_str, "double", "float");
	init_opencl_next(data);
}
