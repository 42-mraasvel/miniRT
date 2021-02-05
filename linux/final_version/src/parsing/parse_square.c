/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 23:20:33 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 10:32:58 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "vectors.h"
#include "objects.h"

static t_m33	square_matrix(t_square *square)
{
	t_cspace	space;

	space = new_space(square->pos, square->norm);
	return (matrix_transpose(matrix_gen(space.right, space.up, space.forward)));
}

int				parse_square(t_scene *scene, char **element)
{
	t_square	square;

	square.type = sq;
	if (ft_count_strings(element) != 5)
		return (parse_error);
	if (parse_coordinates(element[1], &square.pos) != success)
		return (parse_error);
	if (parse_coordinates(element[2], &square.norm) != success)
		return (parse_error);
	vec_normalize(&square.norm);
	square.cob_matrix = square_matrix(&square);
	if (check_number(element[3]) != success)
		return (parse_error);
	square.size = ft_atof(element[3]);
	if (square.size <= 0)
		return (parse_error);
	if (parse_color(element[4], &square.color) != success)
		return (parse_error);
	if (vectvp_pushback(scene->objects, &square, sizeof(t_square)) == -1)
		return (malloc_error);
	return (success);
}
