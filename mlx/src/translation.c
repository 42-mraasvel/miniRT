/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 14:25:04 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/18 17:47:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void translate_square(void *object, t_vec2 translation)
{
	t_square *square;

	square = (t_square*)object;
	square->center.x += translation.x;
	square->center.y += translation.y;

	if (square->center.y - square->length / 2 < 0)
		square->center.y = square->length / 2;
	else if (square->center.y + square->length / 2 > Y)
		square->center.y = Y - square->length / 2;
}
