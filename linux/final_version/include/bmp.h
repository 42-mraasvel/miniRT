/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 10:58:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 10:58:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "minirt.h"

int	save_bmp(t_data *data);
int	create_bmp_file(t_data *data);

#endif
