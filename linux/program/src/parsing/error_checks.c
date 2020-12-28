/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:18:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:52:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

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
		return (file_error);
	return (success);
}

int	check_number(char *information)
{
	while (*information != '\0')
	{
		if (ft_isdigit(*information) == 0 && *information != '.')
		{
			if (*information != '-' && *information != '+')
				return (file_error);
		}
		information++;
	}
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
		return (file_error);
	return (success);
}
