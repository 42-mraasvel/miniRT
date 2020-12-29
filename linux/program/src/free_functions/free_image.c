/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 13:01:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 14:06:58 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "mlx.h"

void	free_image(void *mlx_ptr, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
	free(img);
}
