/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:14:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"
# include "color.h"
# define PARSE_FUNCTIONS 9

typedef int (*parse_ptr)(t_scene*, char**);

/*
** For array of function pointers
** and associated keys
*/

typedef struct	s_parsers
{
	char		id[3];
	parse_ptr	parser;
}				t_parsers;

int	check_arguments(t_data *data, int argc, char *argv[]);
int	init_scene(t_data *data);
int	parse_file(t_data *data, char *pathname);

/*
** Object/Information parsing
*/

int	parse_resolution(t_scene *scene, char **element);

/*
** Parsing utils
*/

int	parse_coordinates(char *information, t_vec3 *point);
int	parse_color(char *information, t_col *col);

/*
** Error handling for file parsing
*/

int	check_coordinates(char *information);
int	check_color(char *information);
int	valid_color(t_col color);

#endif
