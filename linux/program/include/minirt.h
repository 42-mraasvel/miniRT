/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/26 12:09:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef enum	e_errnums
{
	success,
	error,
	input_error,
	option_error,
	argc_error,
	open_error,
	read_error,
	write_error
}				t_errnums;

/*
** error.c
*/

int	ft_perror(char *argument, t_errnums error_type);

#endif
