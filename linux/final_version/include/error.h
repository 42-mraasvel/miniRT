/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 20:49:59 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 21:00:59 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minirt.h"

void	exit_program(t_data *data);
void	ft_perror(t_errors error_type);
int		ft_error(t_data *data, t_errors error_type);

#endif
