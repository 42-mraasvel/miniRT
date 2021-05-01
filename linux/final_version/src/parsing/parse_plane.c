/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 23:18:08 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/01 22:33:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "parsing.h"

int	parse_plane(t_scene *scene, char **element)
{
	t_plane	plane;

	plane.type = pl;
	if (ft_count_strings(element) != 4)
		return (fail);
	if (parse_coordinates(element[1], &plane.pos) != success)
		return (parse_error);
	if (parse_coordinates(element[2], &plane.norm) != success)
		return (parse_error);
	if (vec_len(plane.norm) == 0)
		return (parse_error);
	vec_normalize(&plane.norm);
	if (parse_color(element[3], &plane.color) != success)
		return (parse_error);
	if (vectvp_pushback(scene->objects, &plane, sizeof(t_plane)) == -1)
		return (malloc_error);
	return (success);
}
