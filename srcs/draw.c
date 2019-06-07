/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 17:54:37 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

/*
**	Settings all default values
*/

void			init_default_values(t_data *data)
{
	data->color_value = 0xFFFFFF;
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
	data->max_iteration = 75;
	data->auto_zoom = FALSE;
	data->left_clicking = FALSE;
	data->lock_shape = TRUE;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->fract->constants.r = JULIA_CST_R;
	data->fract->constants.i = JULIA_CST_I;
	get_colors(TRUE);
}

/*
**	Get the color shade (and init it if 'init' is TRUE)
*/

int				*get_colors(t_bool init)
{
	static int	colors[COLORS_COUNT] = {0};

	if (init)
	{
		colors[0] = 0x421E0F;
		colors[1] = 0x19071A;
		colors[2] = 0x09012F;
		colors[3] = 0x040449;
		colors[4] = 0x000764;
		colors[5] = 0x0C2C8A;
		colors[6] = 0x1852B1;
		colors[7] = 0x397DD1;
		colors[8] = 0x86B5E5;
		colors[9] = 0xD3ECF8;
		colors[10] = 0xF1E9BF;
		colors[11] = 0xF8C95F;
		colors[12] = 0xFFAA00;
		colors[13] = 0xCC8000;
		colors[14] = 0x995700;
		colors[15] = 0x6A3403;
	}
	return (colors);
}

/*
**	Given an iteration, returns a color
*/

int				color_from_iteration(int iteration, int max_iteration)
{
	if (iteration < 0)
		iteration = 1;
	if (iteration == max_iteration)
		return (0x000000);
	return (get_colors(FALSE)[iteration % COLORS_COUNT]);
}

/*
**	Draw a string centered on the given position
*/

void			draw_str_centered(t_data *data, int x, int y, char *s)
{
	size_t		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len == 0)
		return ;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x - len * 10 / 2, y, 0xFFFFFF,
		s);
}

/*
**	Draw image, using multi-thread or opencl
*/

int				draw_image(t_data *data)
{
	if (data->opencl == NULL)
		draw_image_thread(data);
	else
		draw_image_opencl(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	draw_variables(data);
	return (1);
}
