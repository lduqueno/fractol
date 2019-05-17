/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:01:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/17 17:09:33 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>

# define CL_SILENCE_DEPRECATION
# ifdef __APPLE__
# include <OpenCL/opencl.h>
# else
# include <CL/cl.h>
# endif

typedef char				t_bool;

# define TRUE				1
# define FALSE				0

# define FRACTAL_COUNT		4

# define WIN_X				1080
# define WIN_Y				720

# define THREAD_COUNT		6

# define MEM_SIZE			(WIN_Y * WIN_X)
# define MAX_SOURCE_SIZE	(0x100000)
# define DATA_COUNT			7
# define COLORS_COUNT		16
# define MAX_ZOOM			125000

# define MALLOC_ERROR		"Unable to allocate memory"
# define MLX_ERROR			"Unable to load the MLX"
# define OPEN_ERROR			"Unable to open opencl file"
# define READ_ERROR			"Unable to read opencl file"
# define OPENCL_ERROR		"Unable to compute opencl file"

typedef struct			s_opencl
{
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_platform_id		platform_id;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	size_t				source_size;
	cl_uint				double_precision_supported;
	char				*source_str;
}						t_opencl;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*win_title;
	void				*img_ptr;
	unsigned int		*pixels;
	double				zoom;
	double				move_x;
	double				move_y;
	unsigned int		max_iteration;
	t_bool				auto_zoom;
	unsigned int		auto_zoom_ticks;
	struct s_fract		*fract;
	struct s_opencl		*opencl;
}						t_data;

typedef struct			s_fract
{
	char				*name;
	t_complex			constants;
	int					(*execute)(t_data *, int, int);
}						t_fract;

typedef struct			s_split_context
{
	t_data				*data;
	int					thread_id;
	int					start_y;
	int					start_x;
	int					end_y;
	int					end_x;
}						t_context;

int					exit_fractol(t_data *data, t_bool free);
int					error(t_data *data, char *error_msg);
void				free_all(t_data *data);

t_fract				*init_fractals(void);
t_fract				*get_fractal_by_name(t_fract *fractals, char *name);

int					execute_julia(t_data *data, int y, int x);
int					execute_mandelbrot(t_data *data, int y, int x);
int					execute_burningship(t_data *data, int y, int x);
int					execute_tricorn(t_data *data, int y, int x);

int					input_red_cross(int key, t_data *data);
int					input_mouse_move(int x, int y, t_data *data);
int					input_mouse_press(int button, int x, int y, t_data *data);
int					input_keyboard(int keycode, t_data *data);
int					input_loop(t_data *data);

int					*get_colors(void);
int					color_from_iteration(int iteration, int max_iteration);
void				draw_image(t_data *data);
void				draw_image_thread(t_data *data);
void				draw_image_opencl(t_data *data);
void				init_opencl(t_data *data);
void				close_opencl(t_opencl *cl, t_bool free_program);

#endif
