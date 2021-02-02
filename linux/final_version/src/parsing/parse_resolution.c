/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:03:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:21:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "libft.h"

int	parse_resolution(t_scene *scene, char **element)
{
	if (ft_count_strings(element) != 3)
		return (error);
	(void)scene;
	(void)element;
	return (success);
}
