/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/15 20:19:09 by lduqueno         ###   ########.fr       */
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
	if (data->auto_zoom)
	{
		data->zoom += data->zoom >= 2.5 ? 0.1 : 0.01;
		draw_image(data);
	}
	return (1);
}

int			input_mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		if (data->zoom > 0.2)
		{
			data->zoom -= 0.15;
			data->max_iteration -= 1;
		}
		draw_image(data);
	}
	else if (button == 4)
	{
		data->zoom += 0.15;
		data->max_iteration += 1;
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
	return (1);
}
