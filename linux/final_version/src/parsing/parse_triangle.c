/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 23:25:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:27:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "objects.h"

int	parse_triangle(t_scene *scene, char **element)
{
	t_triangle	triangle;

	if (ft_count_strings(element) != 5)
		return (parse_error);
	if (parse_coordinates(element[1], &triangle.point1) != success)
		return (parse_error);
	if (parse_coordinates(element[2], &triangle.point2) != success)
		return (parse_error);
	if (parse_coordinates(element[3], &triangle.point3) != success)
		return (parse_error);
	if (parse_color(element[4], &triangle.color) != success)
		return (parse_error);
	if (vectvp_pushback(scene->objects, &triangle, sizeof(t_triangle)) == -1)
		return (malloc_error);
	return (success);
}
