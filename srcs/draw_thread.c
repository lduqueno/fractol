/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:58:30 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/21 09:54:43 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

/*
**	This function is called by every thread. Just draw a part of a fractal
*/

static void			*draw_lines_thread(void *arg)
{
	t_split_context	*context;
	int				y;
	int				x;
	int				result;

	context = (t_split_context *)arg;
	y = context->start_y - 1;
	while (++y < context->end_y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			result = (*(context->data->fract->execute))(context->data, y, x);
			context->data->iterations_array[y * WIN_X + x] = result;
			context->data->pixels[y * WIN_X + x] = color_from_iteration(
					context->data, result);
		}
	}
	free(context);
	pthread_exit(NULL);
	return (NULL);
}

/*
**	Waiting all the threads before updating image
*/

static void			wait_threads(pthread_t *threads)
{
	int				thread_id;

	thread_id = 0;
	while (thread_id < THREAD_COUNT)
	{
		pthread_join(threads[thread_id], NULL);
		thread_id++;
	}
}

/*
**	Split image in several threads
*/

void				draw_image_thread(t_data *data)
{
	pthread_t		threads[THREAD_COUNT];
	t_split_context	*context;
	int				thread_id;
	int				last_line;

	thread_id = 0;
	last_line = 0;
	while (thread_id < THREAD_COUNT)
	{
		if (!(context = (t_split_context *)malloc(sizeof(t_split_context))))
			error(data, MALLOC_ERROR);
		context->data = data;
		context->thread_id = thread_id;
		context->start_y = last_line;
		context->end_y = last_line + WIN_Y / THREAD_COUNT;
		last_line = context->end_y;
		if (context->end_y >= WIN_Y || thread_id == THREAD_COUNT - 1)
			context->end_y = WIN_Y;
		if (pthread_create(&threads[thread_id], NULL, draw_lines_thread,
				context) != 0)
			error(data, MALLOC_ERROR);
		thread_id++;
	}
	wait_threads(threads);
}
