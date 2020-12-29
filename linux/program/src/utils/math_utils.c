/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 16:56:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 17:01:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "math_util.h"

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
