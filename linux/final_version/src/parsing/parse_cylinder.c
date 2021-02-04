/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 23:22:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 11:20:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "objects.h"
#include <math.h>

/*
** Precompute r^2 for
** intersection
*/

int	parse_cylinder(t_scene *scene, char **element)
{
	t_cylinder	cylinder;

	cylinder.type = cy;
	if (ft_count_strings(element) != 6)
		return (parse_error);
	if (parse_coordinates(element[1], &cylinder.pos) != success)
		return (parse_error);
	if (parse_coordinates(element[2], &cylinder.orient) != success)
		return (parse_error);
	vec_normalize(&cylinder.orient);
	if (check_number(element[3]) != success)
		return (parse_error);
	if (check_number(element[4]) != success)
		return (parse_error);
	cylinder.diameter = ft_atof(element[3]);
	cylinder.height = ft_atof(element[4]);
	cylinder.radius_sqrd = powf(cylinder.diameter / 2.f, 2);
	cylinder.height_half = cylinder.height / 2.f;
	if (parse_color(element[5], &cylinder.color) != success)
		return (parse_error);
	if (vectvp_pushback(scene->objects, &cylinder, sizeof(t_cylinder)) == -1)
		return (malloc_error);
	return (success);
}
