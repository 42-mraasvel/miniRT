/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/27 22:16:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"
# include "objects.h"

/*
** Only one:
** 1. Resolution
** 2. Ambient Lightning
**
** Multiple potentially:
** 1. Cameras
** 2. Lights
** 3. Any object
**
*/

typedef struct	s_resolution
{
	int	x;
	int	y;
	int	upp;
}				t_resolution;

typedef struct	s_ambient
{
	double	ratio;
	int		color;
}				t_ambient;

typedef struct	s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
}				t_camera;

typedef struct	s_light
{
	t_vec3	position;
	double	brightness;
	int		color;
}				t_light;

typedef struct	s_scene
{
	t_resolution	resolution;
	t_ambient		ambient;
	t_vect			*cameras;
	t_vect			*lights;
	t_objects		objects;
}				t_scene;

#endif
