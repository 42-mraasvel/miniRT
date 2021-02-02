/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:00:06 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:01:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_col
{
	int	val;
	int	r;
	int	g;
	int	b;
}				t_col;

t_col	color_gen(int r, int g, int b);

#endif
