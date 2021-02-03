/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:01:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 13:49:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "error.h"
#include "mlx.h"
#include "mlx_management.h"
#include "libft.h"

#ifdef BONUS
#include <stdio.h>
void		*render_frame_threaded(void *data)
{
	int			i;
	int			j;
	t_thread	*thread;

	thread = (t_thread*)data;
	j = thread->threadnum;
	printf("Thread start: %d\n", thread->threadnum);
	while (j < thread->data->scene->resolution.y)
	{
		i = 0;
		while (i < thread->data->scene->resolution.x)
		{
			// ft_pixel_put(i, j, compute_color(thread->data));
			i++;
		}
		j += NUMTHREAD;
	}
	printf("Thread end: %d\n", thread->threadnum);
	return (NULL);
}

int			next_frame(t_data *data)
{
	pthread_t	threads[NUMTHREAD];
	t_thread	args[NUMTHREAD];

	if (create_threads(data, threads, args) != success)
		return (ft_error(data, thread_error));
	if (join_threads(threads) != success)
		return (ft_error(data, thread_error));
	push_image(data);
	ft_swap_ptr(data->curr_img, data->next_img);
	return (success);
}

#else

static int	render_frame(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->scene->resolution.y)
	{
		i = 0;
		while (i < data->scene->resolution.x)
		{
			i++;
		}
		j++;
	}
	return (success);
}

int			next_frame(t_data *data)
{
	render_frame(data);
	push_image(data);
	ft_swap_ptr(&data->curr_img, &data->next_img);
	return (success);
}

#endif
