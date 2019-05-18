/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/18 19:45:59 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "float.h"

int			input_red_cross(int keycode, t_data *data)
{
	(void)keycode;
	return (exit_fractol(data, FALSE));
}

int			input_mouse_move(int x, int y, t_data *data)
{
	(void)data;
	if (x < 0 || x > WIN_X || y < 0 || y > WIN_Y)
		return (0);
	return (1);
}

int			input_loop(t_data *data)
{
	double	increase;

	increase = 0.03 * data->zoom;
	if (data->auto_zoom && data->zoom + increase < MAX_ZOOM)
	{
		data->zoom += increase;
		draw_image(data);
	}
	return (1);
}

int			input_mouse_press(int btn, int x, int y, t_data *data)
{
	double	increase;

	increase = 0.05 * data->zoom;
	if (btn == 5 && data->zoom > 0.2)
	{
		data->auto_zoom = FALSE;
		data->zoom -= increase;
		draw_image(data);
	}
	else if (btn == 4 && data->zoom + increase < MAX_ZOOM)
	{
		data->auto_zoom = FALSE;
		data->zoom += increase;
		draw_image(data);
	}
	(void)x;
	(void)y;
	return (1);
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
	else if (keycode == KEY_UP && data->max_iteration < 1500)
		data->max_iteration += 2;
	else if (keycode == KEY_DOWN && data->max_iteration > 3)
		data->max_iteration -= 2;
	else
		return (1);
	draw_image(data);
	return (1);
}
