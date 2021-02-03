/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multithreading.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:14:08 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 13:35:57 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "minirt.h"
#include "multithreading.h"
#include "render.h"

#ifdef BONUS

int	create_threads(
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

int	join_threads(pthread_t threads[NUMTHREAD])
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

#endif
