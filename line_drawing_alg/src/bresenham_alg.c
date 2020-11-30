/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham_alg.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 12:14:59 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 21:27:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** only works for slope <= 1 && slope >= 0
** I gave up and just used the DDA alg, maybe I'll come back to this later.
*/

int	bresenham_alg(int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dy - dx;
	x = x0;
	y = y0;
	printf("%3c | %3c\n", 'x', 'y');
	while (x <= x1)
	{
		printf("%3d | %3d\n", x, y);
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
		x++;
	}
	return (0);
}
