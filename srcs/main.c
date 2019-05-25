/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:00:43 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/25 20:00:58 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

/*
**	Print the usage of the program, and all the available fractals
*/

static int		print_usage(t_fract *fractals)
{
	int		i;

	i = 0;
	ft_printf("Fractol usage : ./fractol (-opencl) <fractal>\nAvailable "
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
**	Init the minilibx window
**	(setting all pointers, creating window, hooking inputs..)
*/

static void		init_mlx(t_data *data)
{
	int		avoid;

	if (!(data->win_title = ft_strjoin("Fractol - ", data->fract->name)))
		error(data, MALLOC_ERROR);
	if (!(data->mlx_ptr = mlx_init()))
		error(data, MLX_ERROR);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X + MENU_X, WIN_Y,
			data->win_title)))
		error(data, MLX_ERROR);
	if (!(data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y)))
		error(data, MLX_ERROR);
	if (!(data->pixels = (unsigned int *)mlx_get_data_addr(data->img_ptr,
			&avoid, &avoid, &avoid)))
		error(data, MLX_ERROR);
	if (!(data->iterations_array = (unsigned int *)malloc(sizeof(unsigned int)
		* WIN_Y * WIN_X)))
		error(data, MLX_ERROR);
}

/*
**	Parse and verify args (find fract name and draw mode)
*/

static int		check_args(t_data *data, t_fract *fracts, int ac, char **av)
{
	int			i;
	t_fract		*found;
	t_bool		use_opencl;

	i = 0;
	found = NULL;
	use_opencl = FALSE;
	while (++i < ac)
		if (ft_strequ(av[i], "-opencl") && !use_opencl)
			use_opencl = TRUE;
		else if (found || !(found = get_fractal_by_name(fracts, av[i])))
			return (print_usage(fracts));
	if (found)
		data->fract = found;
	else
		return (print_usage(fracts));
	if (use_opencl)
	{
		init_opencl(data);
		if (data->opencl->double_precision_supported == 0)
			ft_printf("Double precision is NOT supported on this device.\nThe "
				"quality of the fractal may decrease a lot.\n");
	}
	return (0);
}

/*
**	Settings all the pointers to NULL
*/

void			set_pointers_to_null(t_data *data)
{
	data->left_clicking = FALSE;
	data->opencl = NULL;
	data->fract = NULL;
	data->win_title = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->pixels = NULL;
	data->iterations_array = NULL;
	data->menu_ptr = NULL;
	data->menu_pixels = NULL;
}

/*
**	Main function - start of the program
*/

int				main(int ac, char **av)
{
	t_data		data;
	t_fract		*fracts;

	fracts = init_fractals();
	if (ac < 2 || ac > 3)
		return (print_usage(fracts));
	set_pointers_to_null(&data);
	if (WIN_X < 720 || WIN_Y < 720)
		error(&data, WINDOW_SMALL_ERROR);
	if (check_args(&data, fracts, ac, av))
		return (EXIT_FAILURE);
	init_default_values(&data);
	init_mlx(&data);
	draw_menu(&data);
	draw_image(&data);
	mlx_hook(data.win_ptr, 17, 0, input_red_cross, &data);
	mlx_hook(data.win_ptr, 6, 0, input_mouse_move, &data);
	mlx_hook(data.win_ptr, 4, 0, input_mouse_press, &data);
	mlx_hook(data.win_ptr, 5, 0, input_mouse_release, &data);
	mlx_hook(data.win_ptr, 2, 0, input_keyboard, &data);
	mlx_loop_hook(data.mlx_ptr, input_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
