/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 20:54:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:34:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"

static int	valid_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3)
		return (false);
	if (ft_strcmp(filename + len - 3, ".rt") != 0)
		return (false);
	return (true);
}

/*
** Case:
** 1. Incorrect argument count
** 2. Invalid input string/option
*/

int			check_arguments(t_data *data, int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
		return (ft_error(data, arg_error));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			data->bmp = true;
		else
			return (ft_error(data, arg_error));
	}
	if (!valid_filename(argv[1]))
		return (ft_error(data, arg_error));
	return (success);
}
