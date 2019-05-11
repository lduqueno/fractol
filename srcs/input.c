/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:48:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/11 18:45:41 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int				input_red_cross(int keycode, t_data *data)
{
	(void)keycode;
	return (exit_fractol(data, FALSE));
}

int				input_mouse_move(int x, int y, t_data *data)
{
	(void)data;
	if (x < 0 || x > WIN_X || y < 0 || y > WIN_Y)
		return (0);
	return (1);
}

int				input_keyboard(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		return (exit_fractol(data, TRUE));
	return (1);
}
