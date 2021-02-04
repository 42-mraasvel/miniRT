/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raytracing.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 19:28:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 11:48:10 by mraasvel      ########   odam.nl         */
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

#endif
