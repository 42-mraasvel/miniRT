/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 10:16:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 10:33:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_perror(char *argument, t_errnums error_type)
{
	static const char	*table[] = {
		"success",
		"error",
		"input_error",
		"open_error",
		"read_error",
		"write_error"
	};

	ft_printf("%s\n", table[error_type]);
	if (error_type == input_error)
	{
		if (ft_printf("Invalid argument: Please give a valid pathname with the '.rt' suffix.\n") == -1)
			return (write_error);
	}
	else if (argument != NULL)
		perror(argument);
	return (error_type);
}
