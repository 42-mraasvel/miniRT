/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multithreading_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:14:08 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 11:28:19 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "multithreading.h"
#include "raytracing.h"
#include "libft.h"
#include "mlx_management.h"
#include "ft_error.h"

static void	*render_frame_threaded(void *data)
{
	int			i;
	int			j;
	t_thread	*thread;
	t_vec3		topleft;
	t_ray		ray;

	thread = (t_thread*)data;
	j = thread->threadnum;
	topleft = compute_topleft(
				thread->data->active_cam,
				thread->data->scene->resolution);
	while (j < thread->data->scene->resolution.y)
	{
		i = 0;
		while (i < thread->data->scene->resolution.x)
		{
			ray = compute_ray(topleft, thread->data->active_cam, i, j);
			ft_pixelput(
				thread->data->next_img, i, j,
				compute_color(ray, thread->data));
			i++;
		}
		j += NUMTHREAD;
	}
	return (NULL);
}

static int	create_threads(
	t_data *data,
	pthread_t threads[NUMTHREAD],
	t_thread args[NUMTHREAD])
{
	int	i;

	i = 0;
	while (i < NUMTHREAD)
	{
		args[i].threadnum = i;
		args[i].data = data;
		if (pthread_create(
		&threads[i],
		NULL,
		render_frame_threaded,
		&args[i]) != 0)
			return (thread_error);
		i++;
	}
	return (success);
}

static int	join_threads(pthread_t threads[NUMTHREAD])
{
	int	i;

	i = 0;
	while (i < NUMTHREAD)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (thread_error);
		i++;
	}
	return (success);
}

int			next_frame(t_data *data)
{
	pthread_t	threads[NUMTHREAD];
	t_thread	args[NUMTHREAD];

	if (create_threads(data, threads, args) != success)
		return (ft_error(data, thread_error));
	if (join_threads(threads) != success)
		return (ft_error(data, thread_error));
	if (data->bmp == false)
	{
		push_image(data);
		ft_swap_ptr(&data->curr_img, &data->next_img);
	}
	return (success);
}
