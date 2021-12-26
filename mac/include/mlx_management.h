/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_management.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:34:40 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 11:43:34 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGEMENT_H
# define MLX_MANAGEMENT_H

# include "minirt.h"
# define WINDOW_NAME "MiniMaaRTen"

int		initialize_mlx(t_data *data);
int		init_images(t_data *data);
void	activate_hooks(t_data *data);

/*
** Wrappers / utils
*/

void	ft_pixelput(t_img *img, int x, int y, t_col color);
int		push_image(t_data *data);

#endif
