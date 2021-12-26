/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_enum.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:47:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 15:58:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENUM_H
# define FT_ENUM_H

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef enum	e_errors
{
	fail,
	success,
	arg_error,
	malloc_error,
	parse_error,
	mlx_error,
	bmp_error,
	thread_error
}				t_errors;

#endif
