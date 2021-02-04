/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_images.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 11:30:06 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 12:25:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

static void		*abort_image(void *mlx, t_img *new, int pos)
{
	if (pos >= 2)
		mlx_destroy_image(mlx, new->img_ptr);
	if (pos >= 1)
		free(new);
	return (NULL);
}

static t_img	*mlx_image_wrapper(t_data *data)
{
	t_img	*new;

	new = (t_img*)malloc(1 * sizeof(t_img));
	if (new == NULL)
		return (NULL);
	new->img_ptr = mlx_new_image(
		data->mlx->mlx_ptr,
		data->scene->resolution.x,
		data->scene->resolution.y);
	if (new->img_ptr == NULL)
		return (abort_image(data->mlx, new, 1));
	new->addr = mlx_get_data_addr(
		new->img_ptr,
		&new->bpp,
		&new->size_line,
		&new->endian);
	if (new->addr == NULL)
		return (abort_image(data->mlx, new, 2));
	new->bmp = false;
	new->bpp = new->bpp / 8;
	return (new);
}

int				init_images(t_data *data)
{
	data->curr_img = mlx_image_wrapper(data);
	if (data->curr_img == NULL)
		return (mlx_error);
	data->next_img = mlx_image_wrapper(data);
	if (data->next_img == NULL)
		return (mlx_error);
	return (success);
}
