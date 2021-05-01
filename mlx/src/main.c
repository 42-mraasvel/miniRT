/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 12:30:04 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/25 17:00:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <key_linux.h>
#include <time.h>
#include "headers.h"
#include "mlx.h"

t_col get_color(int r, int g, int b)
{
	return ((t_col){.r = r, .g = g, .b = b, .t = 0});
}

t_col random_color(void)
{
	return (get_color(rand() % 255, rand() % 255, rand() % 255));
}

t_vec2 vec_gen(int x, int y)
{
	return ((t_vec2){.x = x, .y = y});
}

t_square *create_square(t_vec2 center, int size, t_col color)
{
	t_square *square;

	square = malloc(1 * sizeof(t_square));
	if (square == NULL)
		return (NULL);
	*square = (t_square){.type = sq, .center = center, .length = size, .color = color};
	return (square);
}

int main(void)
{
	t_data	data;
	t_mlx	mlx;

	srand(time(0));
	bzero(&data, sizeof(data));
	data.mlx = &mlx;
	if (mlx_wrapper(&mlx) != success)
		exit_program(&data);
	activate_hooks(&data);

	//! Set images
	data.curr_img = get_mlx_image(&data, X, Y);
	if (data.curr_img == NULL)
		exit_program(&data);
	data.next_img = get_mlx_image(&data, X, Y);
	if (data.next_img == NULL)
		exit_program(&data);

	//! Create the main object
	data.obj = (void*)create_square(vec_gen(X / 2, Y / 2), 200, random_color());
	if (data.obj == NULL)
		exit_program(&data);

	mlx_loop_hook(data.mlx->mlx_ptr, next_frame, &data);

	mlx_loop(data.mlx->mlx_ptr);
	exit_program(&data);
}
