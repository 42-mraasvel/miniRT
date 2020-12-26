/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 10:16:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 12:16:51 by mraasvel      ########   odam.nl         */
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

	if (error_type < open_error)
	{
		if (ft_printf("%d: %s\n", error_type, table[error_type]) == -1)
			return (write_error);
	}
	else if (argument != NULL)
		perror(argument);
	if (ft_printf("Use --help for instructions.\n") == -1)
		return (write_error);
	return (error_type);
}
