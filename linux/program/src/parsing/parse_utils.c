/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:07:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 17:33:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	check_information(char **element, int expected)
{
	size_t	i;

	i = 0;
	while (element[i] != NULL)
		i++;
	if (i != expected)
		return (file_error);
	return (success);
}

/*
** Takes string "x,y,z"
** Returns file_error on invalid string (missing coordinates)
** Stores coordinates in 'point'
*/

int	parse_coordinates(char *information, t_vec3 *point)
{
	size_t	i;

	i = 0;
	point->x = ft_atof(information);
	while (information[i] != '\0' && information[i] != ',')
		i++;
	if (information[i] == '\0')
		return (file_error);
	i++;
	point->y = ft_atof(information + i);
	while (information[i] != '\0' && information[i] != ',')
		i++;
	if (information[i] == '\0')
		return (file_error);
	point->z = ft_atof(information + i + 1);
	return (success);
}

/*
** Takes string "255,255,255" as input
** Returns -1 if any color is not in range(0, 256)
** otherwise returns color in (0 R G B) int.
*/

int	parse_color(char *information)
{
	t_color	color;
	int		r;
	int		g;
	int		b;
	size_t	i;

	r = ft_atoi(information);
	i = 0;
	color.color = 0;
	while (information[i] != '\0' && information[i] != ',')
		i++;
	if (information[i] == '\0')
		return (file_error);
	i++;
	g = ft_atoi(information + i);
	while (information[i] != '\0' && information[i] != ',')
		i++;
	b = ft_atoi(information + i + 1);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	color.rgb.r = r;
	color.rgb.b = b;
	color.rgb.g = g;
	return (color.color);
}
