/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:21:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:33:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		color_gen(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

t_col	make_color(int r, int g, int b)
{
	t_col	color;

	color.val = color_gen(r, g, b);
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

// anything above 255 should be clamped to 0-255
t_col	color_add(t_col a, t_col b)
{
	t_col	new;

	new.r = ft_min(a.r + b.r, 255);
	new.g = ft_min(a.g + b.g, 255);
	new.b = ft_min(a.b + b.b, 255);
	new.val = color_gen(new.r, new.g, new.b);
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
	new.val = color_gen(new.r, new.g, new.b);
	return (new);
}

t_col	color_scalar(double s, t_col a)
{
	t_col	new;

	new.r = ft_min((int)(s * (double)a.r), 255);
	new.g = ft_min((int)(s * (double)a.g), 255);
	new.b = ft_min((int)(s * (double)a.b), 255);
	new.val = color_gen(new.r, new.g, new.b);
	return (new);
}

t_col	color_div(double s, t_col a)
{
	return (color_scalar(1.f / s, a));
}
