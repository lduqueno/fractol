/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/21 10:01:54 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "float.h"
#include "ft_printf.h"

/*
**	Handle keyboard other inputs
*/

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
		return (1);
	}
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
	{
		if (keycode == KEY_1)
			data->color_palette = 0;
		else if (keycode == KEY_2)
			data->color_palette = 1;
		else if (keycode == KEY_3)
			data->color_palette = 2;
		get_colors(data, TRUE);
	}
	else
		return (1);
	return (draw_image(data));
}

/*
**	Handle keyboard inputs
*/

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

/*
**	Autozoom loop
*/

int			input_loop(t_data *data)
{
	double	increase;

	increase = 0.007 * data->zoom;
	if (data->auto_zoom && data->zoom + increase < MAX_ZOOM)
	{
		data->zoom += increase;
		data->move_x += data->mouse_x / data->zoom / 4;
		data->move_y += data->mouse_y / data->zoom / 4;
		draw_image(data);
	}
	return (1);
}
