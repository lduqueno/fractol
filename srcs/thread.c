/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:58:30 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/13 18:32:00 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int	color_from_iteration(int iteration, int max_iteration)
{
	if (iteration == max_iteration)
		return (0x000000);
	return (0xFFFFFF / max_iteration * iteration / 10);
	//screen.set_at((x, y), ((3 * n) % 256, (1 * n) % 256, (10 * n) % 256))
}

static void			*draw_lines_thread(void *arg)
{
	t_context	*context;
	int			y;
	int			x;
	int			result;

	context = (t_context *)arg;
	y = context->start_y - 1;
	while (++y < context->end_y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			result = (*(context->data->fract->execute))(context->data, y, x);
			context->data->pixels[y * WIN_X + x] = color_from_iteration(result,
				context->data->max_iteration);
		}
	}
	free(context);
	return (NULL);
}

static void			wait_threads(pthread_t *threads)
{
	int			thread_id;

	thread_id = 0;
	while (thread_id < THREAD_COUNT)
	{
		pthread_join(threads[thread_id], NULL);
		thread_id++;
	}
}

void				draw_image(t_data *data)
{
	pthread_t	threads[THREAD_COUNT];
	t_context	*context;
	int			thread_id;
	int			last_line;

	thread_id = 0;
	last_line = 0;
	while (thread_id < THREAD_COUNT)
	{
		if (!(context = (t_context *)malloc(sizeof(t_context))))
			error(data, MALLOC_ERROR);
		context->data = data;
		context->thread_id = thread_id;
		context->start_y = last_line;
		context->end_y = last_line + WIN_Y / THREAD_COUNT;
		last_line = context->end_y;
		if (context->end_y >= WIN_Y || thread_id == THREAD_COUNT - 1)
			context->end_y = WIN_Y;
		pthread_create(&threads[thread_id], NULL, draw_lines_thread, context);
		thread_id++;
	}
	wait_threads(threads);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
