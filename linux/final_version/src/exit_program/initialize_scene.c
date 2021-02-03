/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_scene.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:09:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 10:23:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libvect.h"
#include "error.h"
#include "minirt.h"
#include "lighting.h"

static int	abort_scene_init(t_data *data, int count)
{
	if (count >= 1)
		vectvp_free(data->scene->objects);
	if (count >= 2)
		vect_free(data->scene->cameras, NULL);
	return (ft_error(data, malloc_error));
}

int	init_scene(t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	scene->objects = vectvp_init(0);
	if (scene->objects == NULL)
		return (abort_scene_init(data, 0));
	scene->cameras = vect_init(0, sizeof(t_camera));
	if (scene->cameras == NULL)
		return (abort_scene_init(data, 1));
	scene->lights = vect_init(0, sizeof(t_light));
	if (scene->lights == NULL)
		return (abort_scene_init(data, 2));
	return (success);
}
