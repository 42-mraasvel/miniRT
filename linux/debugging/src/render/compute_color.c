/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 19:37:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 12:05:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "raytracing.h"
#include "lighting.h"
#include "objects.h"
#include "prototypes.h"

/*
** Compute surface normals
** and viewing direction
*/

static void		compute_hitdata(t_ray *primary_ray, t_hitdata *hitdata)
{
	static const t_compute_normal	compute_normal[] = {
		sphere_normal,
		plane_normal,
		square_normal,
		cylinder_normal,
		triangle_normal
	};

	hitdata->hitpoint = vec_add(
		primary_ray->origin, vec_scalar(primary_ray->t, primary_ray->dir));
	hitdata->normal = compute_normal[*(t_type*)primary_ray->obj](
		hitdata->hitpoint, primary_ray->obj);
	if (vec_dot(primary_ray->dir, hitdata->normal) > 0)
		vec_invert(&hitdata->normal);
	hitdata->hitpoint = vec_add(
		hitdata->hitpoint, vec_scalar(HIT_OFFSET, hitdata->normal));
	hitdata->viewdir = vec_inverted(primary_ray->dir);
	hitdata->color = ((t_gen_obj*)primary_ray->obj)->color;
}

static t_col	add_colors(t_hitdata *data)
{
	t_col	final_color;

	final_color = color_mult(
		color_add(data->ambient, data->diffuse), data->color);
	final_color = color_add(final_color, data->specular);
	return (final_color);
}

t_col			compute_color(t_ray primary_ray, t_data *data)
{
	t_hitdata	hitdata;

	if (trace(&primary_ray, data->scene->objects, data) == false)
		return (compute_ambient(data->scene->ambient));
	compute_hitdata(&primary_ray, &hitdata);
	compute_light_data(
		(t_light*)data->scene->lights->table,
		data->scene->lights->nmemb,
		&hitdata,
		data->scene->objects,
		data); // rm data
	hitdata.ambient = compute_ambient(data->scene->ambient);
	return (add_colors(&hitdata));
}
