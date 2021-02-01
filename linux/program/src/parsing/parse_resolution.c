/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:03:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 12:47:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"
#include "mlx.h"

/*
** First information: 'R'
** Second information: x render size
** Third information: y render size
**
** If the declared size of the scene is greater than the display resolution, the
** window size will be set depending to the current display resolution.
*/

int	parse_resolution(char **element, t_scene *scene, t_mlx mlx)
{
	int	x;
	int	y;

	if (check_information(element, 3) != success)
		return (file_error);
	if (scene->resolution.taken == true)
		return (file_error);
	// mlx_get_screen_size(mlx.mlx_ptr, &x, &y);
	// scene->resolution.x = ft_min(x, ft_atoi(element[1]));
	// scene->resolution.y = ft_min(y, ft_atoi(element[2]));
	scene->resolution.x = ft_atoi(element[1]);
	scene->resolution.y = ft_atoi(element[2]);
	if (scene->resolution.x < 0 || scene->resolution.y < 0)
		return (file_error);
	scene->resolution.taken = true;
	return (success);
}
