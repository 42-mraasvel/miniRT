/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:47:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 17:38:04 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** Invalid if:
** - Invalid number of parameters
** - Invalid number of coordinates
** - Invalid FOV (in range (0, 180)
** - Orientation vector is not normalized to magnitude 1
** Alternative: normalize the orientation vector yourself
*/

int	parse_camera(char **element, t_scene *scene)
{
	t_camera	camera;

	if (check_information(element, 4) != success)
		return (file_error);
	if (parse_coordinates(element[1], &camera.position) != success)
		return (file_error);
	if (parse_coordinates(element[2], &camera.orientation) != success)
		return (file_error);
	camera.fov = ft_atoi(element[3]);
	if (!(camera.fov >= 0 && camera.fov <= 180))
		return (file_error);
	vect_pushback(scene->cameras, &camera);
	return (success);
}
