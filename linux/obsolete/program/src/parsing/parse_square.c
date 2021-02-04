/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 10:37:50 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:31:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"

int	parse_square(char **element, t_vect *squares)
{
	t_square	square;

	if (check_information(element, 5) != success)
		return (file_error);
	if (parse_coordinates(element[1], &square.position) != success)
		return (file_error);
	if (parse_coordinates(element[2], &square.orientation) != success)
		return (file_error);
	square.orientation = vec_normalize(square.orientation);
	if (check_number(element[3]) != success)
		return (file_error);
	square.side_size = ft_atof(element[3]);
	if (square.side_size <= 0)
		return (file_error);
	square.color = parse_color(element[4]);
	if (valid_color(square.color) != success)
		return (file_error);
	if (vect_pushback(squares, &square) == -1)
		return (malloc_error);
	return (success);
}
