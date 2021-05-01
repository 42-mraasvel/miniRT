/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 14:10:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/25 20:39:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "key_linux.h"
#include "mlx.h"
#include "headers.h"
#include "libft.h"

static void draw_square(void *object, t_img *img)
{
	t_square *square;
	int	x, y;
	int i, j;

	square = (t_square*)object;
	y = square->center.y - square->length / 2;
	x = square->center.x - square->length / 2;
	i = 0;
	//! Render cross-hair instead of square
	// while (i < square->length)
	// {
	// 	ft_pixel_put(img, square->center.x, y + i, square->color);
	// 	ft_pixel_put(img, x + i, square->center.y, square->color);
	// 	i++;
	// }
	while (i < square->length)
	{
		j = 0;
		x = square->center.x - square->length / 2;
		while (j < square->length)
		{
			ft_pixel_put(img, x + j, y + i, square->color);
			j++;
		}
		i++;
	}
}

t_bool move_obj(int keycode, void *object) {
	int size;

	size = 25;
	if (keycode == K_W)
		translate_square(object, vec_gen(0, -size));
	else if (keycode == K_A)
		translate_square(object, vec_gen(-size, 0));
	else if (keycode == K_S)
		translate_square(object, vec_gen(0, size));
	else if (keycode == K_D)
		translate_square(object, vec_gen(size, 0));
	else
		return (false);
	return (true);
}

/*
** Write to next image,
** push next image to window
** swap current and next image
*/

int next_frame(t_data *data)
{
	ft_bzero(data->next_img->addr, data->next_img->size_line * Y);
	if (data->obj != NULL)
		draw_square(data->obj, data->next_img);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->next_img->img_ptr, 0, 0);
	ft_swap_ptr(&data->next_img, &data->curr_img);
}
