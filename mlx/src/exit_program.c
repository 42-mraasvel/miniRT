/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:13:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/18 16:18:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "headers.h"

static void free_img(t_data *data, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL)
		mlx_destroy_image(data->mlx->mlx_ptr, img->img_ptr);
	free(img);
}

static void free_mlx(t_data *data)
{
	if (data->mlx == NULL)
		return ;
	free_img(data, data->curr_img);
	free_img(data, data->next_img);
	if (data->mlx->mlx_ptr == NULL)
		return ;
	if (data->mlx->win_ptr != NULL)
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	if (data->mlx->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
}

void exit_program(t_data *data)
{
	free_mlx(data);
	if (data->obj != NULL)
		free(data->obj);
	exit(EXIT_SUCCESS);
}
