/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:11:38 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:31:54 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"

int	parse_cylinder(char **element, t_vect *cylinders)
{
	t_cylinder	cylinder;

	if (check_information(element, 6) != success)
		return (file_error);
	if (parse_coordinates(element[1], &cylinder.position) != success)
		return (file_error);
	if (parse_coordinates(element[2], &cylinder.orientation) != success)
		return (file_error);
	cylinder.orientation = vec_normalize(cylinder.orientation);
	if (check_number(element[3]) != success || check_number(element[4]) != success)
		return (file_error);
	cylinder.diameter = ft_atof(element[3]);
	cylinder.height = ft_atof(element[4]);
	cylinder.color = parse_color(element[5]);
	if (valid_color(cylinder.color) != success)
		return (file_error);
	if (vect_pushback(cylinders, &cylinder) == -1)
		return (malloc_error);
	return (success);
}
