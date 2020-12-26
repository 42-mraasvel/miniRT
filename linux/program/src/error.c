/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 10:16:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 16:52:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_perror(char *argument, t_errnums error_type)
{
	static const char	*table[] = {
		"Success",
		"Error",
		"Input Error: Invalid file.",
		"Option Error: Invalid option.",
		"Input Error: Invalid number of arguments."
	};

	ft_printf("Error\n");
	if (error_type < open_error)
	{
		if (ft_printf("%s\n", table[error_type]) == -1)
			return (write_error);
	}
	else if (argument != NULL)
		perror(argument);
	if (ft_printf("Use --help for instructions.\n") == -1)
		return (write_error);
	return (error_type);
}
