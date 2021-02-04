/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:31:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:57:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void		free_scene(t_scene scene)
{
	vect_free(scene.cameras, NULL);
	vect_free(scene.lights, NULL);
	vect_free(scene.objects.spheres, NULL);
	vect_free(scene.objects.planes, NULL);
	vect_free(scene.objects.squares, NULL);
	vect_free(scene.objects.cylinders, NULL);
	vect_free(scene.objects.triangles, NULL);
}
