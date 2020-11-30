/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 18:34:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 20:24:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef enum	e_errnums
{
	success,
	malloc_error,
	write_error
}				t_errnums;

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

typedef struct	s_triangle
{
	t_pair	points[3];
	t_line	lines[3];
}				t_triangle;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		draw_line(t_pair one, t_pair two, t_data *img);
void	ft_pixel_put(t_data *data, int x, int y, int color);

#endif
