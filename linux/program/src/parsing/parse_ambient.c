/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 22:13:20 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/29 10:04:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	parse_ambient(char **element, t_ambient *ambient)
{
	if (ambient->taken)
		return (file_error);
	if (check_information(element, 3) != success)
		return (file_error);
	if (check_number(element[1]) != success)
		return (file_error);
	ambient->ratio = ft_atof(element[1]);
	if (!ft_inrangef(ambient->ratio, 0.0, 1.0))
		return (file_error);
	ambient->color = parse_color(element[2]);
	if (valid_color(ambient->color) != success)
		return (file_error);
	ambient->taken = 1;
	return (success);
}
