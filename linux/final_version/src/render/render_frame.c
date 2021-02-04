/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:01:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 19:06:33 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "ft_error.h"
#include "mlx.h"
#include "mlx_management.h"
#include "libft.h"
#include "raytracing.h"

#ifdef BONUS

void		*render_frame_threaded(void *data)
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
		ft_swap_ptr(data->curr_img, data->next_img);
	}
	return (success);
}

#else

static int	render_frame(t_data *data)
{
	int	i;
	int	j;
	t_vec3		topleft;
	t_ray		ray;

	j = 0;
	topleft = compute_topleft(
				data->active_cam,
				data->scene->resolution);
	while (j < data->scene->resolution.y)
	{
		i = 0;
		while (i < data->scene->resolution.x)
		{
			ray = compute_ray(topleft, data->active_cam, i, j);
			ft_pixelput(
				data->next_img, i, j,
				compute_color(ray, data));
			i++;
		}
		j++;
	}
	return (success);
}

int			next_frame(t_data *data)
{
	render_frame(data);
	if (data->bmp == false)
	{
		push_image(data);
		ft_swap_ptr(&data->curr_img, &data->next_img);
	}
	return (success);
}

#endif
