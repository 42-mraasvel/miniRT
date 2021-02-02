/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 23:04:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:14:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "objects.h"

int	parse_sphere(t_scene *scene, char **element)
{
	t_sphere	sphere;

	sphere.type = sp;
	if (ft_count_strings(element) != 4)
		return (parse_error);
	if (parse_coordinates(element[1], &sphere.pos) != success)
		return (parse_error);
	if (check_number(element[2]) != success)
		return (parse_error);
	sphere.diameter = ft_atof(element[2]);
	if (sphere.diameter <= 0)
		return (parse_error);
	if (parse_color(element[3], &sphere.color) != success)
		return (parse_error);
	if (vectvp_pushback(scene->objects, &sphere, sizeof(t_sphere)) == -1)
		return (malloc_error);
	return (success);
}
