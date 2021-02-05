/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multithreading.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 18:03:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 20:25:36 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITHREADING_H
# define MULTITHREADING_H

# include "minirt.h"

# ifdef BONUS

#  define NUMTHREAD 4

#  include <pthread.h>
#  include "multithreading.h"

typedef struct	s_thread
{
	int		threadnum;
	t_data	*data;
}				t_thread;

int				join_threads(pthread_t threads[NUMTHREAD]);
int				create_threads(
					t_data *data,
					pthread_t threads[NUMTHREAD],
					t_thread args[NUMTHREAD]);

void			*render_frame_threaded(void *data);

# endif

#endif
