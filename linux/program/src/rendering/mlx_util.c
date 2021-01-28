/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_util.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:46:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:09:35 by mraasvel      ########   odam.nl         */
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

	addr = img.addr + (y * img.size_line) + x * (img.byte_pp);
	*(unsigned int*)addr = color.val;
}
