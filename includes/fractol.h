/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:01:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/06 15:35:11 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define CL_SILENCE_DEPRECATION
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef char				t_bool;

# define TRUE				1
# define FALSE				0

# define FRACTAL_COUNT		5
# ifndef WIN_X
#  define WIN_X				800
# endif
# ifndef WIN_Y
#  define WIN_Y				800
# endif
# define MENU_X				WIN_X / 3

# define THREAD_COUNT		500

# define MAX_SOURCE_SIZE	0x100000
# define DATA_COUNT			7
# define COLORS_COUNT		16
# define MAX_ZOOM			17733711455678103904.0

# define JULIA_CST_R		(-0.7)
# define JULIA_CST_I		0.27015

# define WINDOW_SMALL_ERROR	"The window is too small (minimum is 720x720)"
# define MALLOC_ERROR		"Unable to allocate memory"
# define MLX_ERROR			"Unable to load the MLX"
# define OPEN_ERROR			"Unable to open file"
# define READ_ERROR			"Unable to read opencl file"
# define OPENCL_ERROR		"Unable to compute opencl file"
# define OPENCL_LOG_ERROR	"Unable to build opencl log"
# define LOAD_IMG_ERROR		"Unable to load color wheel image"

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
	cl_mem				pixels_buffer;
	cl_mem				colors_buffer;
	cl_mem				iterations_buffer;
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
	void				*menu_ptr;
	unsigned int		*pixels;
	unsigned int		*iterations_array;
	unsigned int		*menu_pixels;
	unsigned int		color_value;
	int					wheel_width;
	int					wheel_height;
	double				zoom;
	double				move_x;
	double				move_y;
	double				mouse_x;
	double				mouse_y;
	unsigned int		max_iteration;
	t_bool				auto_zoom;
	t_bool				lock_shape;
	t_bool				left_clicking;
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
}						t_split_context;

void					set_pointers_to_null(t_data *data);
void					init_default_values(t_data *data);

int						exit_fractol(t_data *data, t_bool free);
int						error(t_data *data, char *error_msg);
void					free_all(t_data *data);

t_fract					*init_fractals(void);
t_fract					*get_fractal_by_name(t_fract *fractals, char *name);

int						execute_julia(t_data *data, int y, int x);
int						execute_mandelbrot(t_data *data, int y, int x);
int						execute_burningship(t_data *data, int y, int x);
int						execute_tricorn(t_data *data, int y, int x);
int						execute_flower(t_data *data, int y, int x);

int						input_red_cross(int key, t_data *data);
int						input_mouse_move(int x, int y, t_data *data);
int						input_mouse_press(int btn, int x, int y, t_data *data);
int						input_mouse_release(int btn, int x, int y,
							t_data *data);
int						input_keyboard(int keycode, t_data *data);
int						input_loop(t_data *data);

int						*get_colors(t_bool init);
int						color_from_iteration(int iteration, int max_iteration);
t_bool					change_color_by_mouse(t_data *data, int y, int x);

int						draw_image(t_data *data);
void					draw_image_thread(t_data *data);

void					draw_str_centered(t_data *data, int x, int y, char *s);
void					draw_variables(t_data *data);
void					draw_menu(t_data *data);
void					draw_image_opencl(t_data *data);

void					init_opencl(t_data *data);
void					close_opencl(t_opencl *cl);

void					export_to_fdf(t_data *data);

#endif
