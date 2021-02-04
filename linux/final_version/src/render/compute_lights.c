/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_lights.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 18:03:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 20:35:41 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "raytracing.h"
#include "lighting.h"

static t_vec3	compute_reflection_dir(t_vec3 normal, t_vec3 lightdir)
{
	return (vec_normalized(
		vec_sub(
			vec_scalar(2 * vec_dot(normal, lightdir), normal),
			lightdir)));
}

static t_col	compute_specular(
	t_light *light, t_hitdata *data, t_vec3 lightdir)
{
	float	intensity;
	t_vec3	reflect_dir;

	reflect_dir = compute_reflection_dir(data->normal, lightdir);
	intensity = powf(ft_fmax(0, vec_dot(data->viewdir, reflect_dir)), SPEC_EXP);
	intensity = K_SPECULAR * intensity * light->brightness;
	return (color_scalar(intensity, light->color));
}

static t_col	compute_diffuse(t_light *light, t_vec3 lightdir, t_vec3 normal)
{
	float	intensity;

	intensity = ft_fmax(0, vec_dot(lightdir, normal));
	intensity = K_DIFFUSE * intensity * light->brightness;
	return (color_scalar(intensity, light->color));
}

t_col			compute_ambient(t_ambient ambient)
{
	return (color_scalar(ambient.ratio * K_AMBIENT, ambient.color));
}

void			compute_light_data(
	t_light *lights, size_t nmemb,
	t_hitdata *hitdata, t_vectvp *objects)
{
	size_t	i;
	t_vec3	lightdir;
	t_ray	shadow_ray;

	i = 0;
	hitdata->diffuse = color_gen(0, 0, 0);
	hitdata->specular = color_gen(0, 0, 0);
	while (i < nmemb)
	{
		lightdir = vec_normalized(vec_sub(lights[i].pos, hitdata->hitpoint));
		shadow_ray.origin = vec_add(
			hitdata->hitpoint, vec_scalar(HIT_OFFSET, hitdata->normal));
		shadow_ray.dir = lightdir;
		if (trace(&shadow_ray, objects) == false)
		{
			hitdata->diffuse = color_add(
				hitdata->diffuse,
				compute_diffuse(&lights[i], lightdir, hitdata->normal));
			hitdata->specular = color_add(
				hitdata->specular,
				compute_specular(&lights[i], hitdata, lightdir));
		}
		i++;
	}
}
