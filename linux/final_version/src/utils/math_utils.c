/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 17:48:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 22:31:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "vectors.h"

float	deg_to_rad(float degrees)
{
	return (degrees * DTR);
}

float	rad_to_deg(float radians)
{
	return (radians * RTD);
}

/*
** Returns -1 on no solutions
** or solutions <= 0
** otherwise returns smallest solution
** that is greater than 0
*/

float	quadratic_equation(float a, float b, float c)
{
	float	discriminant;
	float	t1;
	float	t2;
	float	root;

	discriminant = b * b - 4.f * a * c;
	if (discriminant < 0.f)
		return (-1.f);
	root = sqrtf(discriminant);
	t1 = (-b + root) / (2 * a);
	t2 = (-b - root) / (2 * a);
	if (t1 <= 0 || t2 <= 0)
		return (ft_fmax(t1, t2));
	return (ft_fmin(t1, t2));
}
