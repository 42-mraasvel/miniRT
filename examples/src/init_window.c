/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/29 10:28:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

/*
** 1. Execute mlx_init to establish a connection to the "correct graphical system".
** 2. Set window size and title using mlx_new_window.
** 3. Call mlx_loop to run the window.
*/

void	init_window_example(void)
{
	void	*mlx;
	void	*mlx_window;
	int		size_x;
	int		size_y;
	char	title[100];

	printf("Please enter X size of the window:\n");
	scanf("%d", &size_x);
	printf("\nPlease enter Y size of the window:\n");
	scanf("%d", &size_y);
	printf("\nPlease enter the name of the window: (no longer than 100 chars)\n");
	scanf("%s", title);

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, size_x, size_y, title);
	printf("\nStart Window Loop\n");
	mlx_loop(mlx);
	printf("End Window Loop\n");
	(void)mlx_window;
	free(mlx);
	return (0);
}
