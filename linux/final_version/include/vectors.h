/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectors.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 16:15:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

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

typedef double	t_m33[3][3];

#endif
