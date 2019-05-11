/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:01:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/11 18:53:15 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

typedef char t_bool;

# define TRUE	1
# define FALSE	0

# define FRACTAL_COUNT	2

# define WIN_X	1080
# define WIN_Y	720

# define MALLOC_ERROR	"Unable to allocate memory"
# define MLX_ERROR		"Unable to load the MLX"

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*win_title;
	void			*img_ptr;
	unsigned int	*pixels;
	struct s_fract	*fract;
}					t_data;

typedef struct		s_fract
{
	char			*name;
	void			(*execute)(t_data *);
}					t_fract;

int					exit_fractol(t_data *data, t_bool free);
int					error(t_data *data, char *error_msg);
void				free_all(t_data *data);

t_fract				*init_fractals(void);
t_fract				*get_fractal_by_name(t_fract *fractals, char *name);

void				execute_julia(t_data *data);
void				execute_mandelbrot(t_data *data);

int					input_red_cross(int key, t_data *data);
int					input_mouse_move(int x, int y, t_data *data);
int					input_keyboard(int keycode, t_data *data);

#endif
