/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 23:36:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:31:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "libft.h"

int	parse_plane(char **element, t_vect *planes)
{
	t_plane	plane;

	if (check_information(element, 4) != success)
		return (file_error);
	if (parse_coordinates(element[1], &plane.position) != success)
		return (file_error);
	if (parse_coordinates(element[2], &plane.orientation) != success)
		return (file_error);
	plane.orientation = vec_normalize(plane.orientation);
	plane.color = parse_color(element[3]);
	if (valid_color(plane.color) != success)
		return (file_error);
	if (vect_pushback(planes, &plane) == -1)
		return (malloc_error);
	return (success);
}
