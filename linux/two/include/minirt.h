/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 22:01:04 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 16:21:21 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <unistd.h>

# define X_WIN 1280
# define Y_WIN 720

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

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

/*
** MLX keycodes
*/

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

/*
** error.c
*/

int	ft_perror(char *string, t_errnum errnum);

#endif
