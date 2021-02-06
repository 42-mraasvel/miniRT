/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:50:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:03:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	parse_ambient(t_scene *scene, char **element)
{
	if (ft_count_strings(element) != 3)
		return (parse_error);
	if (scene->ambient.taken == true)
		return (parse_error);
	if (check_number(element[1]) != success)
		return (parse_error);
	scene->ambient.ratio = ft_atof(element[1]);
	if (parse_color(element[2], &scene->ambient.color) != success)
		return (parse_error);
	scene->ambient.taken = true;
	return (success);
}
