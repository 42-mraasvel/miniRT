/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multithreaded.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 18:18:51 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/30 18:25:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	next_multithreaded_frame(t_data *data)
{
	int			i;
	pthread_t	threads[NUMTHREADS];
	t_tid		arguments[NUMTHREADS];

	i = 0;
	while (i < NUMTHREADS)
	{
		arguments[i].data = data;
		arguments[i].thread_num = i;
		if (pthread_create(&threads[i], NULL, multithreaded_rendering, (void*)&arguments[i]) != 0)
		{
			printf("Thread create error\n");
			return (error);
		}
		i++;
	}
	i = 0;
	while (i < NUMTHREADS)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			printf("Thread join error\n");
			return (error);
		}
		i++;
	}
	return (success);
}
