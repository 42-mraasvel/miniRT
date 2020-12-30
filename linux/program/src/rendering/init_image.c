/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:13:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/30 11:22:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "mlx.h"

static void	*abort_image_init(void *mlx_ptr, t_img *new)
{
	if (new->img_ptr != NULL)
		mlx_destroy_image(mlx_ptr, new->img_ptr);
	free(new);
	return (NULL);
}

t_img		*init_image(t_data *data)
{
	t_img	*new;

	new = (t_img*)malloc(sizeof(t_img));
	if (new == NULL)
		return (NULL);
	new->img_ptr = mlx_new_image(data->mlx->mlx_ptr,
	data->scene->resolution.x, data->scene->resolution.y);
	if (new->img_ptr == NULL)
		return (abort_image_init(data->mlx->mlx_ptr, new));
	new->addr = mlx_get_data_addr(new->img_ptr,
	&new->bpp, &new->size_line, &new->endian);
	if (new->addr == NULL)
		return (abort_image_init(data->mlx->mlx_ptr, new));
	new->byte_pp = new->bpp / 8;
	return (new);
}
#include <time.h>
int			next_frame(t_data *data)
{
	static int	camera_index = 0;
	clock_t	t;

	ft_printf("\033[1;33mRendering Camera Number: %d\033[0;0m\n", camera_index + 1);
	t = clock();
	if (render_image(data->scene, data->next_image,
	((t_camera*)data->scene->cameras->table)[camera_index]) != success)
		return (error);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	ft_printf("\033[1;33mTime taken: %f\033[0;0m\n\n", time_taken);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
	data->mlx->win_ptr, data->next_image->img_ptr, 0, 0);
	ft_swap_ptr(&data->img, &data->next_image);
	camera_index++;
	if (camera_index == data->scene->cameras->nmemb)
		camera_index = 0;
	return (success);
}
