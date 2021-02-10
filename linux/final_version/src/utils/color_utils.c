/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:59:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 18:09:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"

t_col	color_gen(int r, int g, int b)
{
	t_col	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.val = (r << 16) + (g << 8) + b;
	return (result);
}

t_col	color_add(t_col a, t_col b)
{
	return (color_gen(
		ft_min(a.r + b.r, 255),
		ft_min(a.g + b.g, 255),
		ft_min(a.b + b.b, 255)));
}

/*
** Dividing by 255 ensures the value will never be above 255
*/

t_col	color_mult(t_col a, t_col b)
{
	return (color_gen(
		(a.r * b.r) / 255,
		(a.g * b.g) / 255,
		(a.b * b.b) / 255));
}

t_col	color_scalar(double s, t_col a)
{
	return (color_gen(
		ft_min((int)(s * (double)a.r), 255),
		ft_min((int)(s * (double)a.g), 255),
		ft_min((int)(s * (double)a.b), 255)));
}
