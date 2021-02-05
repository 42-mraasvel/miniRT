/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trace.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:46:15 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 12:07:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enum.h"
#include "raytracing.h"
#include "scene.h"
#include "objects.h"

t_bool	intersect_square_debug(t_ray *ray, void *object, t_data *data);

/*
** Array of intersection functions
** using the object type as index
*/

t_bool	trace(t_ray *ray, t_vectvp *objects, t_data *data)
{
	size_t						i;
	t_bool						ret;
	static const t_intersect	intersect[] = {
		intersect_sphere,
		intersect_plane,
		intersect_square,
		intersect_cylinder,
		intersect_triangle
	};

	i = 0;
	ret = false;
	while (i < objects->nmemb)
	{
		if (intersect[*(t_type*)(objects->table[i])](
			ray, objects->table[i]) == true)
		{
			ret = true;
		}
		if (*(t_type*)(objects->table[i]) == sq && data->DEBUG == true) {
			intersect_square_debug(ray, objects->table[i], data);
		}
		i++;
	}
	return (ret);
}
