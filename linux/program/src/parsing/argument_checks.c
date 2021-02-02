/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argument_checks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 10:41:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 21:05:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "prototypes.h"
#include "minirt.h"
#include "libft.h"
#include "libftprintf.h"

static int	print_help(void)
{
	if (ft_printf("Usage:\n\t./exec <--help>\n") == -1)
		return (write_error);
	if (ft_printf("\t./exec <.rt file> <option>\n") == -1)
		return (write_error);
	if (ft_printf("\t\tIf no option is specified:") == -1)
		return (write_error);
	if (ft_printf(" the image is displayed in a window.\nOptions:\n") == -1)
		return (write_error);
	if (ft_printf("\t--save: save the rendered image in .bmp format\n") == -1)
		return (write_error);
	return (input_error);
}

static int	check_argument(t_data *data, char *argument, char *option)
{
	size_t	len;
	int		fd;

	if (option != NULL)
	{
		if (ft_strcmp(option, "--save") != 0)
			return (option_error);
		else
			data->bmp = true;
	}
	len = ft_strlen(argument);
	if (ft_strcmp(argument + len - 3, ".rt") != 0)
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

int			check_input(t_data *data, int argc, char *argv[])
{
	t_errnums	type;

	if (argc != 2 && argc != 3)
	{
		return (ft_perror(NULL, argc_error));
	}
	else if (argc == 2 && ft_strcmp(argv[1], "--help") == 0)
	{
		if (print_help() == write_error)
			return (ft_perror(NULL, write_error));
		return (input_error);
	}
	else
	{
		if (argc == 2)
			type = check_argument(data, argv[1], NULL);
		else
			type = check_argument(data, argv[1], argv[2]);
		if (type != success)
			return (ft_perror(argv[1], type));
	}
	return (success);
}
