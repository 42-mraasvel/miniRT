/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:31:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 12:57:33 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "prototypes.h"
#include "mlx.h"

void	free_program(t_data data, int status)
{
	free_image(data.mlx->mlx_ptr, data.img);
	free_image(data.mlx->mlx_ptr, data.next_image);
	free_scene(*data.scene);
	if (data.mlx->mlx_ptr != NULL)
		free_mlx(*data.mlx);
	if (status == success)
	{
		ft_printf("Exit status: Success\n");
		// exit(EXIT_SUCCESS);
		return ;
	}
	ft_printf("Exit status: Failure\n");
	exit(EXIT_FAILURE);
}
