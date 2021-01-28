/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:23:34 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:35:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"

int	parse_sphere(char **element, t_vect *spheres)
{
	t_sphere	sphere;

	if (check_information(element, 4) != success)
		return (file_error);
	if (parse_coordinates(element[1], &sphere.position) != success)
		return (file_error);
	if (check_number(element[2]) != success)
		return (file_error);
	sphere.diameter = ft_atof(element[2]);
	if (sphere.diameter <= 0)
		return (file_error);
	sphere.color = parse_color(element[3]);
	if (valid_color(sphere.color) != success)
		return (file_error);
	if (vect_pushback(spheres, &sphere) == -1)
		return (malloc_error);
	return (success);
}
