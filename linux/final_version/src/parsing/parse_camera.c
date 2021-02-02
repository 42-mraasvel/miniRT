/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:54:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:03:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	parse_camera(t_scene *scene, char **element)
{
	t_camera	camera;

	if (ft_count_strings(element) != 4)
		return (error);
	if (parse_coordinates(element[1], &camera.pos) != success)
		return (error);
	if (parse_coordinates(element[2], &camera.dir) != success)
		return (error);
	//! NORMALIZE CAMERA DIRECTION
	if (check_number(element[3]) != success)
		return (error);
	camera.fov = ft_atof(element[3]);
	if (camera.fov < 0 || camera.fov > 180)
		return (error);
	//! INITIALIZE CAMERA SPACE
	if (vect_pushback(scene->cameras, &camera) == -1)
		return (malloc_error);
	return (success);
}
