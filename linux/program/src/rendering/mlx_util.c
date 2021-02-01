/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_util.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:46:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 21:58:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Offset:
** y = y * img.size_line
** x = x * (img.bpp / 8)
*/

void	ft_pixel_put(t_img img, int x, int y, t_col color)
{
	char	*addr;
	int		max_offset;
	if (img.bmp == true)
	{
		max_offset = img.height * img.size_line - img.bpp;
		addr = (img.addr + max_offset) - ((y * img.size_line) + x * (img.bpp));
		addr[0] = color.b;
		addr[1] = color.g;
		addr[2] = color.r;
	}
	else
	{
		addr = img.addr + (y * img.size_line) + x * (img.bpp);
		*(unsigned int*)addr = color.val;
	}
}
