/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_mlx.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 11:14:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/01 22:08:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "mlx_management.h"
#include <stdio.h>

static void	check_resolution(t_mlx *mlx, t_resolution *resolution)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	resolution->x = ft_min(x, resolution->x);
	resolution->y = ft_min(y, resolution->y);
}

static int	init_window(t_mlx *mlx, t_scene *scene)
{
	mlx->win_ptr = mlx_new_window(
		mlx->mlx_ptr,
		scene->resolution.x,
		scene->resolution.y,
		WINDOW_NAME);
	if (mlx->win_ptr == NULL)
		return (mlx_error);
	return (success);
}

/*
** 1. Init mlx ptr
** 2. Resize resolution if needed
** 3. Initialize window
** 4. Initialize images
** 5. Activate needed mlx hooks
*/

int			initialize_mlx(t_data *data)
{
	data->mlx->mlx_ptr = mlx_init();
	if (data->mlx->mlx_ptr == NULL)
		return (mlx_error);
	check_resolution(data->mlx, &data->scene->resolution);
	if (init_window(data->mlx, data->scene) != success)
		return (mlx_error);
	if (init_images(data) != success)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		return (mlx_error);
	}
	activate_hooks(data);
	return (success);
}
