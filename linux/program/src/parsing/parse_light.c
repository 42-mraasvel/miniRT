/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 22:03:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 22:24:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	parse_light(char **element, t_vect *lights)
{
	t_light	light;

	if (check_information(element, 4) != success)
		return (file_error);
	if (parse_coordinates(element[1], &light.position) != success)
		return (file_error);
	light.brightness = ft_atof(element[2]);
	if (!ft_inrangef(light.brightness, 0.0, 1.0))
		return (file_error);
	light.color = parse_color(element[3]);
	if (valid_color(light.color) != success)
		return (file_error);
	if (vect_pushback(lights, &light) == -1)
		return (malloc_error);
	return (success);
}
