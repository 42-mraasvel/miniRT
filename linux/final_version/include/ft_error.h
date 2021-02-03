/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 20:49:59 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 15:58:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "minirt.h"

void	exit_program(t_data *data);
void	ft_perror(t_errors error_type);
int		ft_error(t_data *data, t_errors error_type);

#endif
