/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:07:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:08:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"

/*
** Takes string "x,y,z"
** Returns file_error on invalid string (missing coordinates)
** Stores coordinates in 'point'
*/

int	parse_coordinates(char *information, t_vec3 *point)
{
	if (check_coordinates(information) != success)
		return (error);
	point->x = ft_atof(information);
	information = ft_strchr(information, ',');
	if (information == NULL)
		return (file_error);
	point->y = ft_atof(information + 1);
	information = ft_strchr(information + 1, ',');
	if (information == NULL)
		return (file_error);
	point->z = ft_atof(information + 1);
	return (success);
}

/*
** Takes string "255,255,255" as input
** Returns -1 if any color is not in range(0, 256)
** otherwise returns color in (0 R G B) int.
*/

int	parse_color(char *information)
{
	int	r;
	int	g;
	int	b;

	if (check_color(information) != success)
		return (-1);
	r = ft_atoi(information);
	information = ft_strchr(information, ',');
	if (information == NULL)
		return (-1);
	g = ft_atoi(information + 1);
	information = ft_strchr(information + 1, ',');
	if (information == NULL)
		return (-1);
	b = ft_atoi(information + 1);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) + (g << 8) + b);
}
