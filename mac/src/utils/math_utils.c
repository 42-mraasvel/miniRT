/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 17:48:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 10:17:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "vectors.h"

double	deg_to_rad(double degrees)
{
	return (degrees * FT_PI / 180);
}

double	rad_to_deg(double radians)
{
	return (radians * 180 / FT_PI);
}

/*
** Returns -1 on no solutions
** or solutions <= 0
** otherwise returns smallest solution
** that is greater than 0
*/

double	quadratic_equation(double a, double b, double c)
{
	double	discriminant;
	double	t1;
	double	t2;
	double	root;

	discriminant = b * b - 4.f * a * c;
	if (discriminant < 0.0)
		return (-1.f);
	root = sqrtf(discriminant);
	t1 = (-b + root) / (2 * a);
	t2 = (-b - root) / (2 * a);
	if (t1 < 1.0e-6 || t2 < 1.0e-6)
		return (ft_fmax(t1, t2));
	return (ft_fmin(t1, t2));
}
