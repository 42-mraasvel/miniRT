/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 17:04:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	abort_run(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	return (ft_perror(NULL, mlx_error));
}

static void	activate_hooks(t_data *data)
{
	mlx_key_hook(data->mlx->win_ptr, key_hook, data);
	mlx_mouse_hook(data->mlx->win_ptr, mouse_hook, data);
	mlx_expose_hook(data->mlx->win_ptr, expose_hook, data);
}

static int	run(t_data *data)
{
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr,
	data->scene->resolution.x, data->scene->resolution.y, WINDOW_NAME);
	if (data->mlx->win_ptr == NULL)
		return (ft_perror(NULL, mlx_error));
	data->img = init_image(data);
	if (data->img == NULL)
		return (abort_run(data));
	data->next_image = init_image(data);
	if (data->next_image == NULL)
		return (abort_run(data));
	if (next_frame(data) != success)
		return (abort_run(data));
	activate_hooks(data);
	mlx_loop(data->mlx->mlx_ptr);
	return (success);
}

/*
** 1. Check input arguments
** 2. Parse the file
** 3. Render the scene(s)
** 4. Output scene(s) to window or save to .bmp file
** 5. Hook into key_input in order to switch camera
*/

int			main(int argc, char *argv[])
{
	t_data	data;
	t_scene	scene;
	t_mlx	mlx;

	ft_bzero(&data, sizeof(data));
	data.scene = &scene;
	data.mlx = &mlx;
	if (check_input(argc, argv) != success)
		return (0);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (ft_perror(NULL, mlx_error));
	if (parse_file(argv[1], &scene, mlx) != success)
		free_program(data, error);
	if (print_file(&scene) != success)
		free_program(data, error);
	if (run(&data) != success)
		free_program(data, error);
	else
		free_program(data, success);
	return (0);
}
