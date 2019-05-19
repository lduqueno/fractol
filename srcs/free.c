/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:15:33 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/19 17:59:55 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void		free_all(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->menu_ptr)
		mlx_destroy_image(data->mlx_ptr, data->menu_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_strdel(&data->win_title);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->opencl)
	{
		ft_strdel(&data->opencl->source_str);
		free(data->opencl);
	}
	set_pointers_to_null(data);
}

void		close_opencl(t_opencl *cl)
{
	clFlush(cl->command_queue);
	clFinish(cl->command_queue);
	clReleaseKernel(cl->kernel);
	clReleaseProgram(cl->program);
	clReleaseCommandQueue(cl->command_queue);
	clReleaseContext(cl->context);
	clReleaseMemObject(cl->pixels_buffer);
	clReleaseMemObject(cl->colors_buffer);
}
