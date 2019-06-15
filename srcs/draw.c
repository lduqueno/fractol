/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/15 17:34:51 by lduqueno         ###   ########.fr       */
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
	data->auto_zoom = FALSE;
	data->left_clicking = FALSE;
	data->lock_shape = TRUE;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->color_palette = 0;
	data->fract->constants.r = JULIA_CST_R;
	data->fract->constants.i = JULIA_CST_I;
	data->max_iteration = data->fract->max_iteration;
	get_colors(data, TRUE);
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
