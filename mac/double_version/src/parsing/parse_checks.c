/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:41:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 15:59:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_enum.h"
#include "lighting.h"

int	valid_color(t_col color)
{
	if (color.val < 0)
		return (fail);
	if (!ft_inrange(color.r, 0, 255))
		return (fail);
	if (!ft_inrange(color.g, 0, 255))
		return (fail);
	if (!ft_inrange(color.b, 0, 255))
		return (fail);
	return (success);
}

int	check_coordinates(char *information)
{
	int	comma_count;

	comma_count = 0;
	while (ft_isdigit(*information) != 0
	|| *information == '+' || *information == '-')
	{
		information++;
		if (*information == '.')
			information++;
		if (*information == ',')
		{
			comma_count++;
			information++;
		}
	}
	if (comma_count != 2 || *information != '\0')
		return (fail);
	return (success);
}

int	check_color(char *information)
{
	int	comma_count;

	comma_count = 0;
	while (ft_isdigit(*information) != 0)
	{
		information++;
		if (*information == ',')
		{
			comma_count++;
			information++;
		}
	}
	if (comma_count != 2 || *information != '\0')
		return (fail);
	return (success);
}
