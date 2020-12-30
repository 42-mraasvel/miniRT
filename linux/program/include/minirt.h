/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 22:41:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_NAME "MiniMaarten"

typedef enum	e_errnums
{
	success,
	error,
	input_error,
	option_error,
	argc_error,
	gnl_error,
	file_error,
	mlx_error,
	render_error,
	open_error,
	read_error,
	write_error,
	malloc_error
}				t_errnums;

typedef struct	s_found
{
	unsigned char	resolution;
	unsigned char	camera;
}				t_found;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_space
{
	t_vec3	origin;
	t_vec3	base_x;
	t_vec3	base_y;
	t_vec3	base_z;
}				t_space;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		byte_pp;
	int		size_line;
	int		endian;
}				t_img;

typedef union	u_color
{
	int		val;
	struct		s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	}		rgb;
}				t_color;

#endif