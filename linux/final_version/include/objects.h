/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 16:58:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "lighting.h"

typedef enum	e_type
{
	sp,
	pl,
	sq,
	cy,
	tr
}				t_type;

typedef struct	s_gen_obj
{
	t_type	type;
	t_col	color;
}				t_gen_obj;

typedef struct	s_sphere
{
	t_type	type;
	t_col	color;
	t_vec3	pos;
	float	diameter;
	float	radius;
}				t_sphere;

typedef struct	s_plane
{
	t_type	type;
	t_col	color;
	t_vec3	pos;
	t_vec3	norm;
}				t_plane;

typedef struct	s_square
{
	t_type	type;
	t_col	color;
	t_vec3	pos;
	t_vec3	norm;
	float	size;
	t_m33	cob_matrix;
}				t_square;

typedef struct	s_cylinder
{
	t_type	type;
	t_col	color;
	t_vec3	pos;
	t_vec3	orient;
	float	diameter;
	float	radius_sqrd;
	float	height;
	float	height_half;
}				t_cylinder;

typedef struct	s_triangle
{
	t_type	type;
	t_col	color;
	t_vec3	point1;
	t_vec3	point2;
	t_vec3	point3;
	t_vec3	side1;
	t_vec3	side2;
	t_vec3	side3;
	t_vec3	norm;
}				t_triangle;

#endif
