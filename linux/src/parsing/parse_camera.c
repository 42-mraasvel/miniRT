/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:54:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/01 22:32:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "vectors.h"

int				parse_camera(t_scene *scene, char **element)
{
	t_camera	camera;

	if (ft_count_strings(element) != 4)
		return (fail);
	if (parse_coordinates(element[1], &camera.pos) != success)
		return (fail);
	if (parse_coordinates(element[2], &camera.dir) != success)
		return (fail);
	if (vec_len(camera.dir) == 0)
		return (fail);
	vec_normalize(&camera.dir);
	if (check_number(element[3]) != success)
		return (fail);
	camera.fov = ft_atof(element[3]);
	if (camera.fov < 0 || camera.fov > 180)
		return (fail);
	camera.fov = ft_atof(element[3]);
	camera.cspace = new_space(camera.pos, camera.dir);
	if (vect_pushback(scene->cameras, &camera) == -1)
		return (malloc_error);
	return (success);
}
