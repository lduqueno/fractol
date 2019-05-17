/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/17 15:49:54 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int			*get_colors(void)
{
	static int	colors[COLORS_COUNT];

	if (colors[0] != 0x421E0F)
	{
		colors[0] = 0x421E0F;
		colors[1] = 0x19071A;
		colors[2] = 0x09012F;
		colors[3] = 0x040449;
		colors[4] = 0x000764;
		colors[5] = 0x0C2C8A;
		colors[6] = 0x1852B1;
		colors[7] = 0x397DD1;
		colors[8] = 0x86B5E5;
		colors[9] = 0xD3ECF8;
		colors[10] = 0xF1E9BF;
		colors[11] = 0xF8C95F;
		colors[12] = 0xFFAA00;
		colors[13] = 0xCC8000;
		colors[14] = 0x995700;
		colors[15] = 0x6A3403;
	}
	return (colors);
}

int			color_from_iteration(int iteration, int max_iteration)
{
	if (iteration == max_iteration)
		return (0x000000);
	return (get_colors()[iteration % COLORS_COUNT]);
}

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
