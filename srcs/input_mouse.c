/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:14:22 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 18:08:32 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int			input_mouse_move(int x, int y, t_data *data)
{
	if (x < 0 || x > WIN_X + MENU_X || y < 0 || y > WIN_Y)
	{
		data->left_clicking = FALSE;
		data->mouse_x = 0;
		data->mouse_y = 0;
		return (0);
	}
	if (x <= WIN_X)
	{
		data->mouse_x = ((double)((double)x * 2.0) / (double)((double)WIN_X + 1)
			- 1.0) / 3.0;
		data->mouse_y = ((double)((double)y * 2.0) / (double)((double)WIN_Y + 1)
			- 1.0) / 3.0;
		if (!data->lock_shape && ft_strequ(data->fract->name, "julia"))
		{
			data->fract->constants.r = data->mouse_x / data->zoom * 2
				+ JULIA_CST_R;
			data->fract->constants.i = data->mouse_y / data->zoom * 2
				- JULIA_CST_I;
			draw_image(data);
		}
	}
	else if (data->left_clicking)
		change_color_by_mouse(data, y, x);
	return (1);
}

int			input_mouse_release(int btn, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (btn == 1 && data->left_clicking)
		data->left_clicking = FALSE;
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
		data->move_x += data->mouse_x / data->zoom / 3;
		data->move_y += data->mouse_y / data->zoom / 3;
		draw_image(data);
	}
	else if (btn == 1 && change_color_by_mouse(data, y, x))
		data->left_clicking = TRUE;
	return (1);
}
