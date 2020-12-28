/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 21:05:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	print_help(void)
{
	ft_printf("Usage:\n");
	ft_printf("\t./exec <--help>\n");
	ft_printf("\t./exec <.rt file> <option>\n");
	ft_printf("\t\tIf no option is specified:");
	ft_printf(" the image is displayed in a window.\nOptions:\n");
	ft_printf("\t--save: save the rendered image in .bmp format\n");
	return (input_error);
}

static int	check_argument(char *argument, char *option)
{
	size_t	len;
	int		fd;

	if (option != NULL)
		if (ft_strcmp(option, "--save") != 0)
			return (option_error);
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

/*
** 1. Check input arguments
** 2. Parse the file
** 3. Render the scene(s)
** 4. Output scene(s) to window or save to .bmp file
*/

int			main(int argc, char *argv[])
{
	t_scene	scene;
	t_mlx	mlx;

	if (check_input(argc, argv) != success)
		return (0);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (ft_perror(NULL, mlx_error));
	if (parse_file(argv[1], &scene, mlx) != success)
		return (free_program(mlx, scene));
	print_file(&scene);
	free_program(mlx, scene);
	return (0);
}
