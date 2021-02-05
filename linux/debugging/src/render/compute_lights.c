/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_lights.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 18:03:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 15:19:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "libft.h"
#include "raytracing.h"
#include "lighting.h"
#include "debug.h" // rm

static t_vec3	compute_reflection_dir(t_vec3 normal, t_vec3 lightdir)
{
	return (vec_normalized(
		vec_sub(
			vec_scalar(2 * vec_dot(normal, lightdir), normal),
			lightdir)));
}

static t_col	compute_specular(
	t_light *light, t_hitdata *hitdata, t_vec3 lightdir, t_data *data)
{
	double	intensity;
	t_vec3	reflect_dir;

	reflect_dir = compute_reflection_dir(hitdata->normal, lightdir);
	intensity = powf(ft_fmax(0, vec_dot(hitdata->viewdir, reflect_dir)), SPEC_EXP);
	intensity = K_SPECULAR * intensity * light->brightness;
	(void)data;
	return (color_scalar(intensity, light->color));
}

static t_col	compute_diffuse(t_light *light, t_vec3 lightdir, t_vec3 normal, t_data *data)
{
	double	intensity;

	intensity = ft_fmax(0, vec_dot(lightdir, normal));
	intensity = K_DIFFUSE * intensity * light->brightness;
	if (data->DEBUG == true)
		printf("Diffuse: %f\n", intensity);
	(void)data;
	return (color_scalar(intensity, light->color));
}

t_col			compute_ambient(t_ambient ambient)
{
	return (color_scalar(ambient.ratio * K_AMBIENT, ambient.color));
}

void			compute_light_data(
	t_light *lights, size_t nmemb,
	t_hitdata *hitdata, t_vectvp *objects,
	t_data *data)
{
	size_t	i;
	t_ray	shadow_ray;

	i = 0;
	hitdata->diffuse = color_gen(0, 0, 0);
	hitdata->specular = color_gen(0, 0, 0);
	(void)data;
	while (i < nmemb)
	{
		shadow_ray.dir = vec_sub(lights[i].pos, hitdata->hitpoint);
		shadow_ray.t = vec_len(shadow_ray.dir) + 0.1;
		shadow_ray.origin = hitdata->hitpoint;
		vec_normalize(&shadow_ray.dir);
		if (trace(&shadow_ray, objects, data) == false)
		{
			if (data->DEBUG == true)
				printf("LIGHT IS HERE\n");
			hitdata->diffuse = color_add(
				hitdata->diffuse,
				compute_diffuse(&lights[i], shadow_ray.dir, hitdata->normal, data));
			hitdata->specular = color_add(
				hitdata->specular,
				compute_specular(&lights[i], hitdata, shadow_ray.dir, data));
		}
		i++;
	}
}
