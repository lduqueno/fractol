/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:58:30 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/12 18:00:35 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct		s_split_context
{
	t_data			*data;
	int				thread_id;
	int				start_y;
	int				end_y;
}					t_context;

static void			*draw_lines_thread(void *arg)
{
	t_context	*context;
	int			y;
	int			x;
	int			result;

	context = (t_context *)arg;
	y = context->start_y;
	while (y < context->end_y)
	{
		x = 0;
		while (x < WIN_X)
		{
			result = (*(context->data->fract->execute))(context->data, y, x);
			context->data->pixels[y * WIN_X + x] = color_from_iteration(result,
				context->data->fract->max_iteration);
			x++;
		}
		y++;
	}
	free(context);
	printf("Thread %d has finished his draw start=%d, end=%d!\n", context->thread_id + 1, context->start_y, context->end_y);
	return (NULL);
}

void				test_threads(t_data *data)
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
	//	printf("Created context %d - start=%d et end=%d\n", thread_id + 1, context->start_y, context->end_y);
		pthread_create(&threads[thread_id], NULL, draw_lines_thread, context);
		thread_id++;
	}
	thread_id = 0;
	while (thread_id < THREAD_COUNT)
	{
		pthread_join(threads[thread_id], NULL);
		thread_id++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
