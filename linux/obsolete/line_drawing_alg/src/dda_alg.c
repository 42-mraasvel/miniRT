/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_alg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:22:06 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 11:51:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*
** Generate coordinates of all pixels of a line segment between 2 given points.
** https://www.youtube.com/watch?v=W5P8GlaEOSI
** Problem 1: This algorithm is slow because it uses floating point arithmetic.
** Problem 2: It does not give exact coordinates, so we have to round.
*/

int	dda_line_drawing(int x0, int y0, int x1, int y1)
{
	double	x_inc;
	double	y_inc;
	double	startx;
	double	starty;
	int		steps;

	steps = ft_abs(x1 - x0) > ft_abs(y1 - y0) ? ft_abs(x1 - x0) : ft_abs(y1 - y0);
	x_inc = (double)(x1 - x0) / (double)steps;
	y_inc = (double)(y1 - y0) / (double)steps;
	startx = (double)x0;
	starty = (double)y0;
	printf("x_increment: %f\ny_increment: %f\n", x_inc, y_inc);
	printf("\033[1;33m%3c\033[0;0m | \033[1;33m%3c\033[0;0m\n", 'x', 'y');
	while (steps >= 0)
	{
		printf("%3.0f | %3.0f\n", startx, starty);
		startx += x_inc;
		starty += y_inc;
		steps--;
	}
	return (0);
}
