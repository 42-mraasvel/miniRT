/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 09:48:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/01 10:16:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

typedef struct	s_ptrs
{
	void	*a;
	void	*b;
	void	*c;
}				t_ptrs;

static int	free_example(t_ptrs example, t_errnum type, int location)
{
	if (type == success)
	{
		free(example.a);
		free(example.b);
		free(example.c);
	}
	else
	{
		if (location > 0)
			free(example.a);
		if (location > 1)
			free(example.b);
		if (location > 2)
			free(example.c);
	}
	return (type);
}

int	malloc_example(size_t size_a, size_t size_b, size_t size_c)
{
	t_ptrs	example;

	example.a = (void*)malloc(size_a);
	if (example.a == NULL)
		return (malloc_error);
	example.b = (void*)malloc(size_b);
	if (example.b == NULL)
		return (free_example(example, malloc_error, 1));
	example.c = (void*)malloc(size_c);
	if (example.c == NULL)
		return (free_example(example, malloc_error, 2));
	/* do things with pointers */
	return (free_example(example, success, 0));
}