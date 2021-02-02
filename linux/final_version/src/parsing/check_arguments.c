/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 20:54:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 21:04:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error.h"
#include "libft.h"

/*
** Case:
** 1. Incorrect argument count
** 2. Invalid input string/option
*/

int	check_arguments(t_data *data, int argc, char *argv[])
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
	return (success);
}
