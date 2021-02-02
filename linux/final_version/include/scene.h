/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:53:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vectors.h"
# include "libvect.h"
# include "lighting.h"
# include "ft_enum.h"

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		height;
	int		endian;
	t_bool	bmp;
}				t_img;

typedef struct	s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	float	fov;
}				t_camera;

typedef struct	s_resolution
{
	int		x;
	int		y;
	t_bool	taken;
}				t_resolution;

typedef struct	s_scene
{
	t_vect			*cameras;
	t_vect			*lights;
	t_vectvp		*objects;
	t_ambient		ambient;
	t_resolution	resolution;
}				t_scene;

#endif
