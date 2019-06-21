/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:40:20 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/21 10:03:45 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"

/*
**	Update color palette
*/

static void		update_color_preset(t_data *data)
{
	int		i;

	i = 0;
	if (data->color_value < COLORS_COUNT * 100)
		data->color_value += COLORS_COUNT * 100;
	while (i < COLORS_COUNT)
	{
		get_colors(data, FALSE)[i] = data->color_value - i * 100;
		i++;
	}
}

/*
**	Draw second part of the menu
*/

static void		draw_menu_next(t_data *data)
{
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.6),
		"[R] -> Reset image");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.5),
		"[F] -> Export as .fdf");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.41),
		"[1/2/3] -> Colors");
	if (ft_strequ(data->fract->name, "julia"))
		draw_str_centered(data, WIN_X + MENU_X / 2,
			(float)((float)WIN_Y / 1.33), "[L] -> Lock shape");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.27),
		"------");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.21),
		"Use the mouse scroll");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.18),
		"to zoom");
	if (ft_strequ(data->fract->name, "julia"))
	{
		draw_str_centered(data, WIN_X + MENU_X / 2,
			(float)((float)WIN_Y / 1.13), "Move your mouse to");
		draw_str_centered(data, WIN_X + MENU_X / 2,
			(float)((float)WIN_Y / 1.10), "change shape");
	}
}

/*
**	Draw first part of the menu
*/

void			draw_menu(t_data *data)
{
	int		avoid;

	if (!(data->menu_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "resources/c"
					"olor_wheel.xpm", &data->wheel_width, &data->wheel_height)))
		error(data, LOAD_IMG_ERROR);
	data->menu_pixels = (unsigned int *)mlx_get_data_addr(data->menu_ptr,
			&avoid, &avoid, &avoid);
	draw_str_centered(data, WIN_X + MENU_X / 2, WIN_Y / 30, "Color picker");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu_ptr,
		WIN_X + MENU_X / 2 - data->wheel_width / 2, WIN_Y / 12);
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 2.7),
		"--- HELP ---");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 2.4),
		"[WASD] -> Move");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 2.17),
		"[SPACE] -> Auto Zoom");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.99),
		"[ARROW UP] -> Increase");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.91),
		"iterations");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.77),
		"[ARROW DOWN] -> Decrease");
	draw_str_centered(data, WIN_X + MENU_X / 2, (float)((float)WIN_Y / 1.71),
		"iterations");
	draw_menu_next(data);
}

/*
**	Draw top-left informations (zoom and iteration)
*/

void			draw_variables(t_data *data)
{
	char	text[35];

	ft_bzero(text, 35);
	ft_sprintf(text, "Iteration : %d\n", data->max_iteration);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, 0xFFFFFF, text);
	ft_bzero(text, 35);
	ft_sprintf(text, "Zoom : %.2f\n", data->zoom);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5 * 5, 0xFFFFFF, text);
}

/*
**	Change color palette using mouse x and mouse y
*/

t_bool			change_color_by_mouse(t_data *data, int y, int x)
{
	x -= WIN_X + MENU_X / 2 - data->wheel_width / 2;
	y -= WIN_Y / 12;
	if (x > 0 && x < data->wheel_width && y > 0 && y < data->wheel_height)
	{
		if (data->menu_pixels[(y * data->wheel_width) + x] != 4278190080)
		{
			data->left_clicking = TRUE;
			data->color_value = data->menu_pixels[(y * data->wheel_width) + x];
			update_color_preset(data);
			draw_image(data);
			return (TRUE);
		}
	}
	return (FALSE);
}
