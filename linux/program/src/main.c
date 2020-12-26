/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 12:21:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("\t./exec <--help>\n");
	ft_printf("\t./exec <.rt file> <option>\n");
	ft_printf("\t\tIf no option is specified: the image is displayed in a window.\n");
	ft_printf("Options:\n");
	ft_printf("\t--save: save the rendered image in .bmp format\n");
	return (success);
}

static int	check_argument(char *argument, char *option)
{
	size_t	len;
	int		fd;

	if (option != NULL)
		if (ft_strcmp(option, "--save") != 0)
			return (option_error);
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

	if (argc != 2 && argc != 3)
	{
		return (ft_perror(NULL, argc_error));
	}
	else if (argc == 2 && ft_strcmp(argv[1], "--help") == 0)
	{
		return (print_help());
	}
	else
	{
		if (argc == 2)
			type = check_argument(argv[1], NULL);
		else
			type = check_argument(argv[1], argv[2]);
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
