/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:21:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 13:27:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// maybe something like this, one value to push to the screen
// and 3 ints that make it easier to modify
// instead of a union, which I think would fuck with the endiannes
typedef struct	s_col
{
	int color;
	int r;
	int g;
	int b;
}				t_col;

int		color_gen(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

// anything above 255 should be clamped to 0-255
t_col	color_add(t_col a, t_col b)
{
	t_col	new;

	new.r = ft_min(a.r + b.r, 255);
	new.g = ft_min(a.g + b.g, 255);
	new.b = ft_min(a.b + b.b, 255);
	new.color = color_gen(new.r, new.g, new.b);
	return (new);
}

/*
** Dividing by 255 ensures the value will never be above 255
*/

t_col	color_mult(t_col a, t_col b)
{
	t_col new;

	new.r = (a.r * b.r) / 255;
	new.g = (a.g * b.g) / 255;
	new.b = (a.b * b.b) / 255;
	new.color = color_gen(new.r, new.g, new.b);
	return (new);
}

t_col	color_scalar(double s, t_col a)
{
	t_col	new;

	new.r = ft_min((int)(s * (double)a.r), 255);
	new.g = ft_min((int)(s * (double)a.g), 255);
	new.b = ft_min((int)(s * (double)a.b), 255);
	new.color = color_gen(new.r, new.g, new.b);
	return (new);
}
