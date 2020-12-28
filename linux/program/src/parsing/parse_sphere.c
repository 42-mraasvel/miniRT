/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:23:34 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:55:42 by mraasvel      ########   odam.nl         */
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
	if (sphere.diameter < 0)
		return (file_error);
	sphere.color.val = parse_color(element[3]);
	if (sphere.color.val < 0)
		return (file_error);
	if (vect_pushback(spheres, &sphere) == -1)
		return (malloc_error);
	return (success);
}
