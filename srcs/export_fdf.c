/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:12:34 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/05 17:54:44 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"

/*
**	Export current frame to a FdF map.
**	For best result, use https://github.com/indy728/42-fdf.git to visualize map
*/

void		export_to_fdf(t_data *data)
{
	char	*file_name;
	int		fd;
	int		y;
	int		x;

	y = -4;
	if (!(file_name = ft_strjoin(data->fract->name, ".fdf")))
		error(data, MALLOC_ERROR);
	if ((fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0600)) < 0)
	{
		free(file_name);
		error(data, OPEN_ERROR);
	}
	while ((y += 4) < WIN_Y)
	{
		x = -4;
		while ((x += 4) < WIN_X)
			ft_dprintf(fd, "%s%lu,%#x", x == 0 ? "" : " ",
				data->iterations_array[y * WIN_X + x],
				data->pixels[y * WIN_X + x]);
		write(fd, "\n", 1);
	}
	close(fd);
	free(file_name);
}
