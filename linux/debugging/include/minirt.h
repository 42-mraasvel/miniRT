/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 18:05:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"
# include "ft_enum.h"
# include <stdio.h> // rm

# define BONUS

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_bool	destroy;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_img		*curr_img;
	t_img		*next_img;
	t_camera	*active_cam;
	t_bool		bmp;
	t_errors	errnum;
	t_bool		DEBUG;
}				t_data;

#endif
