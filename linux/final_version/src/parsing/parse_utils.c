/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:37:34 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:36:36 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectors.h"
#include "parsing.h"
#include "ft_enum.h"
#include "color.h"

int	parse_coordinates(char *information, t_vec3 *point)
{
	if (check_coordinates(information) != success)
		return (error);
	point->x = ft_atof(information);
	information = ft_strchr(information, ',');
	point->y = ft_atof(information + 1);
	information = ft_strchr(information + 1, ',');
	point->z = ft_atof(information + 1);
	return (success);
}

int	parse_color(char *information, t_col *col)
{
	if (check_color(information) != success)
		return (error);
	col->r = ft_atoi(information);
	information = ft_strchr(information, ',');
	col->g = ft_atoi(information + 1);
	information = ft_strchr(information + 1, ',');
	col->b = ft_atoi(information + 1);
	*col = color_gen(col->r, col->g, col->b);
	if (valid_color(*col) != success)
		return (error);
	return (success);
}

int	check_number(char *information)
{
	while (*information != '\0')
	{
		if (ft_isdigit(*information) == 0 && *information != '.')
		{
			if (*information != '-' && *information != '+')
				return (error);
		}
		information++;
	}
	return (success);
}

int	valid_data(t_data *data)
{
	if (data->scene->cameras->nmemb == 0)
		return (false);
	if (data->scene->resolution.taken == false)
		return (false);
	if (data->scene->ambient.taken == false)
		return (false);
	return (true);
}
