/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/17 15:19:25 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

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
	if (data->auto_zoom && data->zoom < MAX_ZOOM)
	{
		data->zoom += 0.01 * data->zoom;
		if (++data->auto_zoom_ticks % 20 == 0)
			data->max_iteration += 2;
		draw_image(data);
	}
	return (1);
}

int			input_mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 5 && data->zoom > 0.2)
	{
		data->auto_zoom = FALSE;
		data->zoom -= 0.05 * data->zoom;
		data->max_iteration -= 2;
		draw_image(data);
	}
	else if (button == 4 && data->zoom < MAX_ZOOM)
	{
		data->auto_zoom = FALSE;
		data->zoom += 0.05 * data->zoom;
		data->max_iteration += 2;
		draw_image(data);
	}
	return (1);
}

int			input_keyboard(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		return (exit_fractol(data, TRUE));
	else if (keycode == KEY_SPACEBAR)
		data->auto_zoom = !data->auto_zoom;
	else if (keycode == KEY_UP)
		data->move_y -= 0.05 / data->zoom;
	else if (keycode == KEY_DOWN)
		data->move_y += 0.05 / data->zoom;
	else if (keycode == KEY_LEFT)
		data->move_x -= 0.05 / data->zoom;
	else if (keycode == KEY_RIGHT)
		data->move_x += 0.05 / data->zoom;
	else
		return (1);
	draw_image(data);
	return (1);
}
