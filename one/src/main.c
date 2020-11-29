/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/29 10:21:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

int	main(void)
{
	void	*mlx;
	// void	*mlx_window;

	mlx = mlx_init();
	mlx_new_window(mlx, 480, 200, "Hello world!");
	printf("Start Loop\n");
	mlx_loop(mlx);
	printf("End Loop\n");
	// (void)mlx_window;
	free(mlx);
	return (0);
}
