/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:45:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 20:17:11 by mraasvel      ########   odam.nl         */
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

t_vec3	calculate_image_start(t_scene *scene, t_space camera_space, t_camera camera)
{
	t_vec3	start;
	double	image_distance;
	double	x_half;
	double	y_half;

	x_half = (double)scene->resolution.x / 2.0;
	y_half = (double)scene->resolution.y / 2.0;
	image_distance = (x_half / 2.0) / (tan(deg_to_rad(camera.fov / 2)));
	start = vec_scalar(camera_space.base_z, image_distance);
	start = vec_sub(start, vec_scalar(camera_space.base_x, x_half));
	start = vec_sub(start, vec_scalar(camera_space.base_y, y_half));
	return (start);
}

/*
** Takes origin and direction as input.
** Returns 3 basis vectors relative to
** the world coordinate system.
*/

t_space	new_coordinate_space(t_vec3 origin, t_vec3 base_z)
{
	t_space	new;

	new.origin = origin;
	new.base_z = base_z;
	new.base_x = vec_rotate_y(base_z, deg_to_rad(-90));
	new.base_y = vec_cross(new.base_x, new.base_z);
	return (new);
}

/*
** Raytracing Algorithm:
** 1. For Each Pixel
** 2. Shoot a ray from camera to pixel
** 3. Calculate intersection for each object
** 4. Take closest intersection
** 5. Shoot a ray from intersection to each light
** 6. Calculate color using this information
** 7. Change the color of this pixel
*/

int	render_image(t_scene *scene, t_img *img, t_camera camera)
{
	int		i;
	int		j;
	t_space	camera_space;
	t_vec3	start;
	t_vec3	pixel_position;

	print_camera_info(camera);
	i = 0;
	camera_space = new_coordinate_space(camera.position, camera.orientation);
	start = calculate_image_start(scene, camera_space, camera);
	ft_printf("Start: %.2f %.2f %.2f %.2f\n", -1.0, -10.0, -100.0, -1000.0);
	print_vec(start);
	printf("\n");
	while (i < scene->resolution.y)
	{
		j = 0;
		pixel_position = start;
		while (j < scene->resolution.x)
		{
			// ray_tracing(camera_position, vec_dir(camera_origin, pixel_position), scene);
			vec_add(pixel_position, camera_space.base_x);
			j++;
		}
		vec_add(start, camera_space.base_y);
		i++;
	}
	return (success);
}
