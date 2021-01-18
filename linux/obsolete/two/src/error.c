/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 17:55:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/17 18:01:49 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	ft_perror(char *string, t_errnum errnum)
{
	static const char	*err_table[] = {
		"success",
		"error",
		"mlx error"
	};

	ft_putstr(string);
	ft_putstr(": ");
	ft_putendl_fd((char*)err_table[errnum], 2);
	return (error);
}
