/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raytracing.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 19:28:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 18:39:13 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "minirt.h"

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	dir;
	void	*obj;
	float	t;
}				t_ray;

typedef struct	s_hitdata
{
	t_vec3	normal;
	t_vec3	viewdir;
	t_vec3	hitpoint;
	t_col	color;
	t_col	ambient;
	t_col	diffuse;
	t_col	specular;
}				t_hitdata;

/*
** Two solutions for
** quadratic equation
*/

typedef struct	s_sol
{
	float	t1;
	float	t2;
}				t_sol;

typedef t_bool (*t_intersect)(t_ray*, void *);

t_vec3	compute_pixel(t_vec3 topleft, t_camera *camera, int x, int y);
t_vec3	compute_topleft(t_camera *camera, t_resolution res);
t_ray	compute_ray(t_vec3 topleft, t_camera *camera, int x, int y);

t_col	compute_color(t_ray primary_ray, t_data *data);
t_bool	trace(t_ray *ray, t_vectvp *objects);

/*
** Intersection functions
*/

float	intersect_plane_wrap(t_ray ray, t_vec3 norm, t_vec3 pos);
t_bool	update_ray(t_ray *ray, float t, void *object);

t_bool	intersect_sphere(t_ray *ray, void *sphere);
t_bool	intersect_plane(t_ray *ray, void *object);
t_bool	intersect_square(t_ray *ray, void *object);
t_bool	intersect_cylinder(t_ray *ray, void *object);
t_bool	intersect_triangle(t_ray *ray, void *object);

/*
** Normal computation
*/

typedef t_vec3 (*t_compute_normal)(t_vec3, void*);

t_vec3	sphere_normal(t_vec3 point, void *object);
t_vec3	plane_normal(t_vec3 point, void *object);
t_vec3	square_normal(t_vec3 point, void *object);
t_vec3	cylinder_normal(t_vec3 point, void *object);
t_vec3	triangle_normal(t_vec3 point, void *object);

#endif
