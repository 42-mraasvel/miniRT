/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:45:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/26 20:48:14 by mraasvel      ########   odam.nl         */
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

	x_half = (double)scene->resolution.x / 2.0 - 0.5;
	y_half = (double)scene->resolution.y / 2.0 - 0.5;
	image_distance = x_half / (tan(deg_to_rad(camera.fov / 2)));
	start = vec_add(camera_space.origin, vec_scalar(camera_space.base_z, image_distance));
	start = vec_sub(start, vec_scalar(camera_space.base_x, x_half));
	start = vec_add(start, vec_scalar(camera_space.base_y, y_half));
	return (start);
}

int	ray_tracing(t_camera camera, t_vec3 direction, t_scene *scene, t_color *color)
{
	t_intersection_data data;

	data.t = -1.0;
	if (ray_intersection(camera.position, direction, scene->objects, &data) != success)
	{
		color->val = 0;
		return (success);
	}
	//! Compute distance intersection point to all light sources
	//! Compute color using the parameters: light intensity, surface normal, viewing direction

	//! Here we are testing some basic shading
	get_viewing_direction(&data, camera);
	check_normal(&data);
	facing_ratio(&data);
	color->val = data.color.val;
	return (success);
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
	// move camera_space into struct of camera, to make camera rotation easy
	// start can also be part of t_camera
	t_space	camera_space;
	t_vec3	start;
	t_vec3	pixel_position;
	t_color	color;

	print_camera_info(camera);
	i = 0;
	camera_space = new_coordinate_space(camera.position, camera.orientation);
	ft_printf("Magnitudes: %.2f %.2f %.2f\n", vec_magnitude(camera_space.base_x),vec_magnitude(camera_space.base_y),vec_magnitude(camera_space.base_z));
	start = calculate_image_start(scene, camera_space, camera);
	while (i < scene->resolution.y)
	{
		j = 0;
		pixel_position = start;
		while (j < scene->resolution.x)
		{
			if (ray_tracing(camera, vec_dir(camera.position, pixel_position), scene, &color) != success)
				return (render_error);
			ft_pixel_put(*img, j, i, color);
			pixel_position = vec_add(pixel_position, camera_space.base_x);
			j++;
			break;
		}
		break;
		start = vec_sub(start, camera_space.base_y);
		i++;
	}
	return (success);
}
