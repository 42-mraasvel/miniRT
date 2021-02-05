/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 16:56:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 23:12:53 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "math_util.h"
#include "minirt.h"
#include "prototypes.h"

/*
** Convert degree to radians
*/

double	deg_to_rad(double degrees)
{
	return (degrees * DTR);
}

/*
** radians to degrees
*/

double	rad_to_deg(double radians)
{
	return (radians * RTD);
}

double	distance(t_vec3 a, t_vec3 b)
{
	return (vec_magnitude(vec_sub(a, b)));
}
