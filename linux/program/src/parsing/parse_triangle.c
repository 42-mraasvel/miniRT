/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:38:15 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/11 15:42:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int parse_triangle(char **element, t_vect *triangles)
{
	t_triangle	triangle;

	if (check_information(element, 5) != success)
		return (file_error);
	if (parse_coordinates(element[1], &triangle.point_1) != success)
		return (file_error);
	if (parse_coordinates(element[2], &triangle.point_2) != success)
		return (file_error);
	if (parse_coordinates(element[3], &triangle.point_3) != success)
		return (file_error);
	triangle.color.val = parse_color(element[4]);
	if (triangle.color.val < 0)
		return (file_error);
	if (vect_pushback(triangles, &triangle) == -1)
		return (malloc_error);
	return (success);
}
