/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 19:08:38 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/07 23:06:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minirt.h"
#include "ft_enum.h"
#include "ft_error.h"
#include "mlx.h"

static void	free_image(void *mlx_ptr, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
	else if (img->bmp == true)
		free(img->addr);
	free(img);
}

static void	free_mlx(t_data *data)
{
	if (data->mlx == NULL)
		return ;
	free_image(data->mlx->mlx_ptr, data->curr_img);
	free_image(data->mlx->mlx_ptr, data->next_img);
	if (data->mlx->win_ptr != NULL && data->mlx->destroy == false)
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	if (data->mlx->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx->mlx_ptr);
	if (data->bmp != true)
		free(data->mlx->mlx_ptr);
}

static void	free_scene(t_data *data)
{
	if (data->scene == NULL)
		return ;
	vectvp_free(data->scene->objects);
	vect_free(data->scene->cameras, NULL);
	vect_free(data->scene->lights, NULL);
}

void		exit_program(t_data *data)
{
	free_scene(data);
	free_mlx(data);
	if (data->errnum != success)
	{
		ft_perror(data->errnum);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
