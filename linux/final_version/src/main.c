/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:18:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 15:59:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "ft_error.h"
#include "ft_enum.h"
#include "parsing.h"
#include "bmp.h"
#include "mlx_management.h"
#include "mlx.h"
#include "render.h"

int	run(t_data *data)
{
	data->active_cam = &((t_camera*)data->scene->cameras->table)[0];
	if (data->bmp == true)
		return (save_bmp(data));
	if (initialize_mlx(data) != success)
		return (ft_error(data, mlx_error));
	if (next_frame(data) != success)
		return (fail);
	mlx_loop(data->mlx->mlx_ptr);
	return (success);
}

/*
** 1. Argument checks
** 2. Parse RT file
** 3. BMP or MLX
** 4. Render image to window or file
** 5. Free/exit program
*/

int	main(int argc, char *argv[])
{
	t_data	data;
	t_scene	scene;
	t_mlx	mlx;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&mlx, sizeof(t_mlx));
	ft_bzero(&scene, sizeof(t_scene));
	data.errnum = success;
	if (check_arguments(&data, argc, argv) != success)
		exit_program(&data);
	data.scene = &scene;
	if (init_scene(&data) != success)
		exit_program(&data);
	if (parse_file(&data, argv[1]) != success)
		exit_program(&data);
	data.mlx = &mlx;
	if (run(&data) != success)
		exit_program(&data);
	exit_program(&data);
	return (0);
}
