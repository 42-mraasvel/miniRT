/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:06:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"
# include "libvect.h"

/*
** Objects:
** 1. Sphere
** 2. Plane
** 3. Square
** 4. Cylinder
** 5. Triangle
**
** Bonus:
** 1. Cube
** 2. Pyramid
** 3. Cone, Hyperboloid, Paraboloid
*/

typedef struct	s_objects
{
	t_vect	*spheres;
	t_vect	*planes;
	t_vect	*squares;
	t_vect	*cylinders;
	t_vect	*triangles;
}				t_objects;

typedef struct	s_sphere
{
	t_vec3	position;
	double	diameter;
	t_col	color;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3	position;
	t_vec3	orientation;
	t_col	color;
}				t_plane;

typedef struct	s_square
{
	t_vec3	position;
	t_vec3	orientation;
	double	side_size;
	t_col	color;
}				t_square;

typedef struct	s_cylinder
{
	t_vec3	position;
	t_vec3	orientation;
	double	diameter;
	double	height;
	t_col	color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vec3	point_1;
	t_vec3	point_2;
	t_vec3	point_3;
	t_col	color;
}				t_triangle;

#endif
