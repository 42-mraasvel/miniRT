/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/29 10:46:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

/*
** 1. Execute mlx_init to establish a connection to the "correct graphical system".
** 2. Set window size and title using mlx_new_window.
** 3. Call mlx_loop to run the window.
** Potential for user input, or just change variable values
*/

void	init_window_example(void)
{
	void	*mlx;
	void	*mlx_window;

	int		size_x = 1280;
	int		size_y = 720;
	char	title[100] = "Window Name";

	printf("Initialize Window Example:\n\n");
	// printf("Please enter X size of the window:\n");
	// scanf("%d", &size_x);
	// printf("\nPlease enter Y size of the window:\n");
	// scanf("%d", &size_y);
	// printf("\nPlease enter the name of the window: (no longer than 100 chars)\n");
	// scanf("%s", title);

	printf("Initialize MLX\n");
	mlx = mlx_init();
	printf("Initialize window with:\n\tsize_x: |%d|\n\tsize_y: |%d|\n\ttitle: |%s|\n", size_x, size_y, title);
	mlx_window = mlx_new_window(mlx, size_x, size_y, title);
	printf("\nStart Window Loop\n");
	mlx_loop(mlx);
	printf("End Window Loop\n");
	(void)mlx_window;
	free(mlx);
}
