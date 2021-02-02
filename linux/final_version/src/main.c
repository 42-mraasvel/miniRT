/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:18:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:14:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "error.h"
#include "parsing.h"

// int	run(t_data *data)
// {
// 	if (data->bmp == true)
// 		return (save_bmp(data));
// 	if (initialize_mlx(data) != success)
// 		return (error);
// 	return (success);
// }

int	main(int argc, char *argv[])
{
	t_data	data;
	t_scene	scene;
	t_mlx	mlx;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&mlx, sizeof(t_mlx));
	ft_bzero(&scene, sizeof(t_scene));
	if (check_arguments(&data, argc, argv) != success)
		exit_program(&data);
	if (init_scene(&data) != success)
		exit_program(&data);
	data.scene = &scene;
	if (parse_file(&data, argv[2]) != success)
		exit_program(&data);
	data.mlx = &mlx;
	// if (run(&data) != success)
	// 	exit_program(&data);
	exit_program(&data);
	return (0);
}
