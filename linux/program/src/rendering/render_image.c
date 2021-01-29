/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:45:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/29 10:55:34 by mraasvel      ########   odam.nl         */
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

t_col	compute_ambient(t_ambient ambient)
{
	return (color_scalar(ambient.ratio, ambient.color));
}

t_col	compute_lights(t_vec3 point, t_vect *lights, t_intersection_data data, t_objects objects)
{
	size_t	i;
	t_light	*table;
	t_intersection_data	useless;
	t_col	light_color;
	t_vec3	light_dir;
	double	light_intensity;
	double	distance_normalizer;

	i = 0;
	table = (t_light*)lights->table;
	light_color = make_color(0, 0, 0);
	while (i < lights->nmemb)
	{
		useless.t = -1;
		light_dir = vec_normalize(vec_sub(table[i].position, point));
		if (ray_intersection(point, light_dir, objects, &useless) == success) {
			// print_vec(point);
			// printf(" : T: %f\n", useless.t);
		}
		if (useless.t < 0 || useless.t > distance(point, table[i].position))
		{
			//! no intersection between point and light source so add color
			// distance_normalizer = 4 * M_PI * pow(distance(point, table[i].position), 2);
			// distance_normalizer = 1;
			// light_intensity = table[i].brightness * (K_DIFFUSE * ft_fmax(0, vec_dot(light_dir, data.surface_normal))) / distance(point, table[i].position);
			light_intensity = table[i].brightness * (K_DIFFUSE * ft_fmax(0, vec_dot(light_dir, data.surface_normal)));
			light_color = color_add(light_color, color_scalar(light_intensity, table[i].color));
		}
		i++;
	}
	return (light_color);
}

t_col	compute_color(t_intersection_data data, t_scene *scene)
{
	t_col	light_color;
	t_vec3	shadow_ray_origin;

	shadow_ray_origin = vec_add(data.intersection_point, vec_scalar(data.surface_normal, NORMAL_BIAS));
	light_color = make_color(0, 0, 0);
	light_color = compute_lights(shadow_ray_origin, scene->lights, data, scene->objects);
	light_color = color_add(light_color, compute_ambient(scene->ambient));
	return (color_mult(light_color, data.color));
}

int	ray_tracing(t_camera camera, t_vec3 direction, t_scene *scene, t_col *color)
{
	t_intersection_data data;

	data.t = -1.0;
	if (ray_intersection(camera.position, direction, scene->objects, &data) != success)
	{
		*color = compute_ambient(scene->ambient);
		return (success);
	}
	data.intersection_point = vec_add(camera.position, vec_scalar(direction, data.t));
	//! Compute distance intersection point to all light sources
	//! Compute color using the parameters: light intensity, surface normal, viewing direction

	//! Here we are testing some basic shading
	get_viewing_direction(&data, camera);
	check_normal(&data);
	// facing_ratio(&data);
	*color = compute_color(data, scene);
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
	t_col	color;

	print_camera_info(camera);
	i = 0;
	camera_space = new_coordinate_space(camera.position, camera.orientation);
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
		}
		start = vec_sub(start, camera_space.base_y);
		i++;
	}
	return (success);
}
