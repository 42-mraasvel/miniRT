/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 17:31:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "minirt.h"
# include "objects.h"
# include "scene.h"

/*
** src/parsing/
*/

int		parse_file(char *pathname, t_scene *scene, t_mlx mlx);
int		parse_resolution(char **element, t_scene *scene, t_mlx mlx);
int		parse_camera(char **element, t_scene *scene);

/*
** parsing_utils
*/

int		check_information(char **element, int expected);
int		parse_color(char *information);
int		parse_coordinates(char *information, t_vec3 *point);
/*
** scene.c
*/

int		init_scene(t_scene *scene);

/*
** error.c
*/

int		ft_perror(char *argument, t_errnums error_type);

/*
** Free Functions
*/

int		free_program(t_mlx mlx, t_scene scene);
void	free_scene(t_scene scene);
void	free_mlx(t_mlx mlx);

#endif
