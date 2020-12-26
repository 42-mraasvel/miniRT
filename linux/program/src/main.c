/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 10:43:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	check_argument(char *argument)
{
	size_t	len;
	int		fd;

	len = ft_strlen(argument);
	if (argument[len - 1] != 't' || argument[len - 2] != 'r' || argument[len - 3] != '.')
		return (input_error);
	fd = open(argument, O_RDONLY);
	if (fd == -1)
		return (open_error);
	if (read(fd, NULL, 0) != 0)
	{
		close(fd);
		return (read_error);
	}
	close(fd);
	return (success);
}

static int	check_input(int argc, char *argv[])
{
	t_errnums	type;

	if (argc != 2)
	{
		return (ft_perror(NULL, input_error));
	}
	else
	{
		type = check_argument(argv[1]);
		if (type != success)
			return (ft_perror(argv[1], type));
	}
	return (success);
}

int	main(int argc, char *argv[])
{
	if (check_input(argc, argv) != success)
		return (0);
	return (0);
}
