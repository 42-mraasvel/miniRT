/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:59:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:04:19 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	parse_light(t_scene *scene, char **element)
{
	t_light	light;

	if (ft_count_strings(element) != 4)
		return (parse_error);
	if (parse_coordinates(element[1], &light.pos) != success)
		return (parse_error);
	if (check_number(element[2]) != success)
		return (parse_error);
	light.brightness = ft_atof(element[2]);
	if (!ft_inrangef(light.brightness, 0.0f, 1.0f))
		return (parse_error);
	if (parse_color(element[3], &light.color) != success)
		return (parse_error);
	if (vect_pushback(scene->lights, &light) == -1)
		return (malloc_error);
	return (success);
}
