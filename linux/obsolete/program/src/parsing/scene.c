/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 21:58:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 16:31:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	abort_init(t_scene scene, int position)
{
	vect_free(scene.cameras, NULL);
	if (position > 1)
		vect_free(scene.lights, NULL);
	if (position > 2)
		vect_free(scene.objects.spheres, NULL);
	if (position > 3)
		vect_free(scene.objects.planes, NULL);
	if (position > 4)
		vect_free(scene.objects.squares, NULL);
	if (position > 5)
		vect_free(scene.objects.cylinders, NULL);
	if (position > 6)
		vect_free(scene.objects.triangles, NULL);
	return (malloc_error);
}

int			init_scene(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
	scene->cameras = vect_init(0, sizeof(t_camera));
	if (scene->cameras == NULL)
		return (error);
	scene->lights = vect_init(0, sizeof(t_light));
	if (scene->lights == NULL)
		return (abort_init(*scene, 1));
	scene->objects.spheres = vect_init(0, sizeof(t_sphere));
	if (scene->objects.spheres == NULL)
		return (abort_init(*scene, 2));
	scene->objects.planes = vect_init(0, sizeof(t_plane));
	if (scene->objects.planes == NULL)
		return (abort_init(*scene, 3));
	scene->objects.squares = vect_init(0, sizeof(t_square));
	if (scene->objects.squares == NULL)
		return (abort_init(*scene, 4));
	scene->objects.cylinders = vect_init(0, sizeof(t_cylinder));
	if (scene->objects.cylinders == NULL)
		return (abort_init(*scene, 5));
	scene->objects.triangles = vect_init(0, sizeof(t_triangle));
	if (scene->objects.triangles == NULL)
		return (abort_init(*scene, 6));
	return (success);
}
