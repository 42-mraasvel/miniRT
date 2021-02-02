/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:18:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 18:48:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	run(t_data *data)
{
	if (data->bmp == true)
		return (save_bmp(data));
	if (initialize_mlx(data) != success)
		return (error);
	return (success);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_scene	scene;
	t_mlx	mlx;

	ft_bzero(&data, sizeof(data));
	data.mlx = &mlx;
	data.scene = &scene;
	if (check_arguments(argc, argv, &data) != success)
		exit_program(&data);
	if (parse_file(scene) != success)
		exit_program(&data);
	if (valid_data(&data) == false)
		exit_program(&data);
	if (run(&data) != success)
		exit_program(&data);
	exit_program(&data);
	return (0);
}
