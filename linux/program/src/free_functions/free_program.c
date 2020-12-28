/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:31:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:56:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	free_program(t_mlx mlx, t_scene scene)
{
	free_scene(scene);
	free_mlx(mlx);
	return (success);
}
