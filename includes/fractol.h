/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:01:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/11 18:02:53 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

# define FRACTAL_COUNT	1

# define WIN_X	1920
# define WIN_Y	1080

# define MALLOC_ERROR	"Unable to allocate memory"

typedef struct		s_fract
{
	char			*name;
}					t_fract;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*win_title;
	void			*img_ptr;
	unsigned int	*pixels;
	t_fract			*fract;
}					t_data;

int					exit_fractol(t_data *data);
int					error(t_data *data, char *error_msg);
void				free_all(t_data *data);
t_fract				*init_fractals(void);
t_fract				*get_fractal_by_name(t_fract *fractals, char *name);

int					input_red_cross(int key, t_data *data);
int					input_mouse_move(int x, int y, t_data *data);
int					input_keyboard(int keycode, t_data *data);

#endif
