/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 17:59:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "vectors.h"
# include "ft_bool.h"

typedef struct	s_col
{
	int	value;
	int	r;
	int	g;
	int	b;
}				t_col;

typedef struct	s_ambient
{
	float	ratio;
	t_col	color;
	t_bool	taken;
}				t_ambient;

typedef struct	s_light
{
	t_vec3	pos;
	float	brightness;
	t_col	color;
}				t_light;

#endif
