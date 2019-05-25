/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/25 20:23:12 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "float.h"

static int	next_input_keyboard(int keycode, t_data *data)
{
	if (keycode == KEY_UP && data->max_iteration < 1500)
		data->max_iteration += 2;
	else if (keycode == KEY_DOWN && data->max_iteration > 3)
		data->max_iteration -= 2;
	else if (keycode == KEY_F)
	{
		ft_printf("Writing fractal in %s.fdf..\n", data->fract->name);
		export_to_fdf(data);
		ft_printf("Done!\n");
	}
	else
		return (1);
	return (draw_image(data));
}

int			input_keyboard(int keycode, t_data *data)
{
	double	increase;

	increase = 0.05 / data->zoom;
	if (keycode == KEY_ESCAPE)
		return (exit_fractol(data, TRUE));
	else if (keycode == KEY_SPACEBAR)
		data->auto_zoom = !data->auto_zoom;
	else if (keycode == KEY_W && data->move_y - increase > -FLT_MAX)
		data->move_y -= increase;
	else if (keycode == KEY_S && data->move_y + increase < FLT_MAX)
		data->move_y += increase;
	else if (keycode == KEY_A && data->move_x - increase > -FLT_MAX)
		data->move_x -= increase;
	else if (keycode == KEY_D && data->move_x + increase < FLT_MAX)
		data->move_x += increase;
	else if (keycode == KEY_R)
		init_default_values(data);
	else if (keycode == KEY_L)
		data->lock_shape = !data->lock_shape;
	else
		return (next_input_keyboard(keycode, data));
	return (draw_image(data));
}

int			input_red_cross(int keycode, t_data *data)
{
	(void)keycode;
	return (exit_fractol(data, FALSE));
}

int			input_loop(t_data *data)
{
	double	increase;

	increase = 0.01 * data->zoom;
	if (data->auto_zoom && data->zoom + increase < MAX_ZOOM)
	{
		data->zoom += increase;
		data->move_x += data->mouse_x / data->zoom / 3;
		data->move_y += data->mouse_y / data->zoom / 3;
		draw_image(data);
	}
	return (1);
}
