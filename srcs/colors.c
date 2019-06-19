/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:51:58 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/19 14:51:51 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Set blue palette
*/

static void		set_blue_palette(int *colors)
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

/*
**	Set red palette
*/

static void		set_red_palette(int *colors)
{
	colors[0] = 0x380707;
	colors[1] = 0x431321;
	colors[2] = 0x6B2339;
	colors[3] = 0xB41E1E;
	colors[4] = 0xD91B1B;
	colors[5] = 0xFF002A;
	colors[6] = 0xF1294A;
	colors[7] = 0xE2445E;
	colors[8] = 0xE24B64;
	colors[9] = 0xD87585;
	colors[10] = 0xE78595;
	colors[11] = 0xE7C485;
	colors[12] = 0xEBA252;
	colors[13] = 0xEE6517;
	colors[14] = 0xFA5200;
	colors[15] = 0xC5543C;
}

/*
**	Set psychedelic palette
*/

static void		set_psy_palette(int *colors)
{
	colors[0] = 0xFF0000;
	colors[1] = 0xFF6000;
	colors[2] = 0xFFDE00;
	colors[3] = 0xF7FF00;
	colors[4] = 0x96FF00;
	colors[5] = 0x04FF00;
	colors[6] = 0x00FF82;
	colors[7] = 0x00FFEE;
	colors[8] = 0x00CDFF;
	colors[9] = 0x0079FF;
	colors[10] = 0x002EFF;
	colors[11] = 0x5400FF;
	colors[12] = 0xA300FF;
	colors[13] = 0xEE00FF;
	colors[14] = 0xF00C4;
	colors[15] = 0xFF008E;
}

/*
**	Get the color shade (and init it if 'init' is TRUE)
*/

int				*get_colors(t_data *data, t_bool init)
{
	static int	colors[COLORS_COUNT] = {0};

	if (init)
	{
		if (data->color_palette == 0)
			set_blue_palette(colors);
		else if (data->color_palette == 1)
			set_red_palette(colors);
		else if (data->color_palette == 2)
			set_psy_palette(colors);
	}
	return (colors);
}

/*
**	Given an iteration, returns a color
*/

int				color_from_iteration(t_data *data, int iteration)
{
	if (iteration < 0)
		iteration = 1;
	if (iteration == (int)data->max_iteration)
		return (0x000000);
	return (get_colors(data, FALSE)[iteration % COLORS_COUNT]);
}
