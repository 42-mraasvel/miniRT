/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:59:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:01:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_col	color_gen(int r, int g, int b)
{
	t_col	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.val = (r << 16) + (g << 8) + b;
	return (result);
}
