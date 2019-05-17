/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/17 13:38:21 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			draw_text(t_data *data)
{
	char	text[20];

	ft_bzero(text, 20);
	ft_sprintf(text, "Iteration : %d\n", data->max_iteration);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5,
		0xFFFFFF, text);
	ft_bzero(text, 20);
	ft_sprintf(text, "Zoom : %.2f\n", data->zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5 * 5,
		0xFFFFFF, text);
}

void				draw_image(t_data *data)
{
	if (data->opencl == NULL)
		draw_image_thread(data);
	else
		draw_image_opencl(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	draw_text(data);
}
