/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 19:50:22 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/29 19:53:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		line_size;
	int		bits_per_pixel;
	int		endian;
}				t_data;


#endif
