/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 23:27:03 by mraasvel      ########   odam.nl         */
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

typedef struct	s_sphere
{
	t_type	type;
	t_vec3	pos;
	float	diameter;
	t_col	color;
}				t_sphere;

typedef struct	s_plane
{
	t_type	type;
	t_vec3	pos;
	t_vec3	norm;
	t_col	color;
}				t_plane;

typedef struct	s_square
{
	t_type	type;
	t_vec3	pos;
	t_vec3	norm;
	float	size;
	t_col	color;
}				t_square;

typedef struct	s_cylinder
{
	t_type	type;
	t_vec3	pos;
	t_vec3	orient;
	float	diameter;
	float	height;
	t_col	color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_type	type;
	t_vec3	point1;
	t_vec3	point2;
	t_vec3	point3;
	t_col	color;
}				t_triangle;

#endif
