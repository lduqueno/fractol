/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:48:38 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/12 16:07:49 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	color_from_iteration(int iteration, int max_iteration)
{
	if (iteration == max_iteration)
		return (0x000000);
	if (iteration < 150)
		return (0xFF0000);
	else
		return (0x00FF00);
	return (iteration);
}

void				init_default_values(t_data *data)
{
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
}

void				draw_image(t_data *data)
{
	int			y;
	int			x;
	int			fract_iteration;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			fract_iteration = (*(data->fract->execute))(data, y, x);
			data->pixels[y * WIN_X + x] = color_from_iteration(fract_iteration,
				data->fract->max_iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
