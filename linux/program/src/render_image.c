/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:45:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 14:59:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	print_image_info(t_img *img)
{
	printf("BPP: %d\nSize_line: %d\nEndian: %d\n", img->bpp, img->size_line, img->endian);
}

void	print_camera_info(t_camera c)
{
	printf("FOV: %f\nPosition:\n", c.fov);
	printf("<%.2f %.2f %.2f>\n", c.position.x, c.position.y, c.position.z);
	printf("Orientation:\n");
	printf("<%.2f %.2f %.2f>\n", c.orientation.x, c.orientation.y, c.orientation.z);
	printf("\n");
}

int	render_image(t_scene *scene, t_img *img, t_camera camera)
{
	int	i;
	int	j;
	t_color	col;

	print_camera_info(camera);
	i = 0;
	col.val = 0x00FF0000;
	while (i < scene->resolution.y)
	{
		j = 0;
		while (j < scene->resolution.x)
		{
			ft_pixel_put(*img, j, i, col);
			j++;
		}
		i++;
	}
	return (success);
}
