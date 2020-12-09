/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 18:34:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/01 10:02:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef enum	e_errnum
{
	success,
	malloc_error,
	write_error
}				t_errnum;

typedef struct	s_pair
{
	int	x;
	int	y;
}				t_pair;

typedef struct	s_line
{
	t_pair	start;
	t_pair	end;
	int		delta_x;
	int		delta_y;
	int		size;
	t_pair	*coordinates;
}				t_line;

/*
** vert_points stores the lowest and highest y of the triangle points.
** vert_points.x = highest(south in pixel map) y, vert_points.y = lowest(north in pixel map) y
** hori_points stores lowest and highest x for each y between lowest and highest y.
** hori_points.x is the rightmost(largest) x, hori_points.y is the leftmost(lowest) x
*/

typedef struct	s_triangle
{
	t_pair	points[3];
	t_line	lines[3];
	t_pair	vert_points;
	t_pair	*hori_points;
}				t_triangle;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_pixel_put(t_data *data, int x, int y, int color);
t_line	generate_line(int x0, int y0, int x1, int y1);
int		draw_line(t_pair one, t_pair two, t_data *img);
int		draw_triangle(t_triangle triangle, t_data *img);

#endif
