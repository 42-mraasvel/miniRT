/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 21:58:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_NAME "MiniMaaRTen"

# define BMPNAME "image.bmp"
# define MULTITHREADING 1
# define NUMTHREADS 4

typedef enum	e_bool
{
	false,
	true
}				t_bool;

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

typedef struct	s_m34
{
	double	m[3][4];
}				t_m34;

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
	int		size_line;
	int		height;
	int		endian;
	t_bool	bmp;
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

// maybe something like this, one value to push to the screen
// and 3 ints that make it easier to modify
// instead of a union, which I think would fuck with the endiannes
typedef struct	s_col
{
	int val;
	int r;
	int g;
	int b;
}				t_col;

typedef struct	s_intersection_data
{
	double	t;
	t_vec3	intersection_point;
	t_vec3	surface_normal;
	t_col	color;
	t_vec3	viewing_direction;
}				t_intersection_data;

typedef struct	s_hitdata
{
	double	t;
	t_vec3	normal;
	t_vec3	view_dir;
	t_col	obj_color;
}				t_hitdata;

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	void		*object;
	t_hitdata	data;
}				t_ray;

#endif
