/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pixel_put.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 20:17:15 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 20:21:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Writes color (changes pixel value) at offset.
** Offset formula explanation:
** 1. bits_per_pixel / 8 = byte size of the pixel. (if 32 bits per pixel size = 4, like an int).
** 2. line_length = total bytes in a window line ((max)x * 4 (if 32 bits per pixel)).
** 3. So (max)y * line_length = total bytes in the entire window.
** 4. This will give you the y coordinate, then you add the x coordinate, and you have the offset.
*/

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
