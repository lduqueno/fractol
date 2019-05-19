/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:14:22 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/19 16:46:35 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			input_mouse_move(int x, int y, t_data *data)
{
	if (x < 0 || x > WIN_X + MENU_X || y < 0 || y > WIN_Y)
	{
		data->left_clicking = FALSE;
		return (0);
	}
	if (data->left_clicking)
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
		draw_image(data);
	}
	else if (btn == 1 && change_color_by_mouse(data, y, x))
		data->left_clicking = TRUE;
	return (1);
}
