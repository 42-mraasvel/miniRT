/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 10:16:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 22:41:42 by mraasvel      ########   odam.nl         */
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
		"Input Error: Invalid number of arguments.",
		"GNL: Error encountered while reading file.",
		"File Error: encountered while parsing file.",
		"MLX Error: error returned from MLX function.",
		"Render Error: encountered while rendering image."
	};

	ft_printf("Error\n");
	if (error_type < open_error)
	{
		if (ft_printf("%s\n", table[error_type]) == -1)
			return (write_error);
		if (ft_printf("Use --help for instructions.\n") == -1)
			return (write_error);
	}
	else if (argument != NULL)
		perror(argument);
	else
		perror("Error");
	return (error_type);
}
