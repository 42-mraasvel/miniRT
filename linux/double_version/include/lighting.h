/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 00:17:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "vectors.h"
# include "ft_enum.h"
# include "color.h"

# define K_AMBIENT 1
# define K_DIFFUSE 0.6
# define K_SPECULAR 0.08
# define SPEC_EXP 10

typedef struct	s_ambient
{
	double	ratio;
	t_col	color;
	t_bool	taken;
}				t_ambient;

typedef struct	s_light
{
	t_vec3	pos;
	double	brightness;
	t_col	color;
}				t_light;

#endif
