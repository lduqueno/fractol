/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/17 13:11:59 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Print the usage of the program, and all the available fractals
*/

static int		print_usage(t_fract *fractals)
{
	int		i;

	i = 0;
	ft_printf("Fractol usage : ./fractol (-opencl) <fractal>\nAvailable"
		"fractals : ");
	while (i < FRACTAL_COUNT)
	{
		if (i > 0)
			ft_printf(", ");
		ft_printf("%s", fractals[i].name);
		i++;
	}
	ft_printf(".\n");
	return (EXIT_FAILURE);
}

/*
**	Init our main struct t_data
**	(setting all pointers to NULL, creating window, hooking inputs..)
*/

static void		init_mlx(t_data *data)
{
	int		avoid;

	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->pixels = NULL;
	data->opencl = NULL;
	if (!(data->win_title = ft_strjoin("Fractol - ", data->fract->name)))
		error(data, MALLOC_ERROR);
	if (!(data->mlx_ptr = mlx_init()))
		error(data, MLX_ERROR);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			data->win_title)))
		error(data, MLX_ERROR);
	if (!(data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y)))
		error(data, MLX_ERROR);
	if (!(data->pixels = (unsigned int *)mlx_get_data_addr(data->img_ptr,
			&avoid, &avoid, &avoid)))
		error(data, MLX_ERROR);
}

static void		init_default_values(t_data *data)
{
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
	data->max_iteration = 100;
	data->auto_zoom = 0;
	data->auto_zoom_ticks = 0;
}

int				main(int ac, char **av)
{
	t_data		data;
	t_fract		*fractals;

	fractals = init_fractals();
	if (/*ac != 2 || */!(data.fract = get_fractal_by_name(fractals, av[1])))
		return (print_usage(fractals));
	init_mlx(&data);
	init_default_values(&data);
	if (ac == 3 && ft_strequ(av[2], "-opencl"))
		init_opencl(&data);
	draw_image(&data);
	mlx_hook(data.win_ptr, 17, 0, input_red_cross, &data);
	mlx_hook(data.win_ptr, 6, 0, input_mouse_move, &data);
	mlx_hook(data.win_ptr, 4, 0, input_mouse_press, &data);
	mlx_hook(data.win_ptr, 2, 0, input_keyboard, &data);
	mlx_loop_hook(data.mlx_ptr, input_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
