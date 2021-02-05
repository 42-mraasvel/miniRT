/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:32:29 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:56:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "mlx.h"

void	free_mlx(t_mlx mlx)
{
	if (mlx.mlx_ptr != NULL)
		mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
}
