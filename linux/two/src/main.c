/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 22:00:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/16 23:03:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	void	*mlx_ptr;

	printf("lol\n");
	mlx_ptr = mlx_init();
	free(mlx_ptr);
	return (0);
}
