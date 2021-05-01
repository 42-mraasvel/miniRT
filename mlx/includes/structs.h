/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:07:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/17 14:36:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool {
	false,
	true
} t_bool;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}	t_mlx;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bpp;
	int size_line;
	int endian;
} t_img;

typedef struct s_data
{
	t_mlx *mlx;
	t_img *curr_img;
	t_img *next_img;
	void *obj;
} t_data;

typedef union e_col
{
	int color;
	struct {
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char t;
	};
} t_col;

typedef struct s_vec2
{
	int x;
	int y;
} t_vec2;


/* Objects */

typedef enum e_type
{
	sq,
	ci,
	tr
} t_type;

typedef struct s_square
{
	t_type type;
	t_col color;
	t_vec2 center;
	int length;
} t_square;

typedef struct s_circle
{
	t_type type;
	t_col color;
	t_vec2 center;
	float diameter;
} t_circle;

typedef struct s_triangle
{
	t_type type;
	t_col color;
	t_vec2 point1;
	t_vec2 point2;
	t_vec2 point3;
} t_triangle;


#endif
