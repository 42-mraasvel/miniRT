/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:03:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 10:45:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "libft.h"

int	parse_resolution(t_scene *scene, char **element)
{
	if (ft_count_strings(element) != 3)
		return (parse_error);
	if (scene->resolution.taken == true)
		return (parse_error);
	if (check_number(element[1]) != success)
		return (parse_error);
	if (check_number(element[2]) != success)
		return (parse_error);
	scene->resolution.x = ft_atoi(element[1]);
	scene->resolution.y = ft_atoi(element[2]);
	scene->resolution.taken = true;
	if (scene->resolution.x <= 0 || scene->resolution.y <= 0)
		return (parse_error);
	return (success);
}
