/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectors.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 13:43:56 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# define FT_PI 3.14159265358979323846
# define DTR FT_PI / 180
# define RTD 180 / FT_PI

# include "ft_enum.h"

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_cspace
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	origin;
}				t_cspace;

typedef struct	s_m33
{
	double	m[3][3];
}				t_m33;

t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_scalar(float scalar, t_vec3 v);
t_vec3			vec_cross(t_vec3 a, t_vec3 b);
float			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_gen(float x, float y, float z);
void			vec_normalize(t_vec3 *v);
t_vec3			vec_normalized(t_vec3 v);
float			vec_len(t_vec3 v);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_bool			vec_parallel(t_vec3 a, t_vec3 b);
float			vec_sqrd(t_vec3 v);
void			vec_invert(t_vec3 *v);
t_vec3			vec_inverted(t_vec3 v);

t_cspace		new_space(t_vec3 origin, t_vec3 forward);

t_m33			matrix_transpose(t_m33 matrix);
t_vec3			matrix_vec_mult(t_m33 m, t_vec3 v);
t_m33			matrix_gen(t_vec3 c1, t_vec3 c2, t_vec3 c3);

float			rad_to_deg(float radians);
float			deg_to_rad(float degrees);
float			quadratic_equation(float a, float b, float c);

void		print_vec(t_vec3 v); // rm
void		print_matrix(t_m33 m); // rm

#endif
