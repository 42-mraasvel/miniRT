/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 19:15:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef union	u_color
{
	int	color;
	struct		s_bits
	{
		unsigned char	t;
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
	}	rgb;
}				t_color;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_camera
{
	t_point	position;
	t_point	orientation_vector;
	double	fov;
}				t_camera;

typedef struct	s_screen
{
	int	x;
	int	y;
}				t_screen;

typedef struct	s_alightning
{
	double	ratio;
	t_color	color;
}				t_alightning;

typedef struct	s_scene
{
	t_camera		camera;
	t_screen		screen;
	t_alightning	ambient_lightning;
}				t_scene;

int				render_scene(t_scene scene, t_mlx data);

#endif
