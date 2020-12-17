/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 22:01:04 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/17 21:46:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>

# define X_WIN 800
# define Y_WIN 800

typedef enum	e_errnum
{
	success,
	error,
	mlx_error
}				t_errnum;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

/*
** error.c
*/

int	ft_perror(char *string, t_errnum errnum);

#endif
