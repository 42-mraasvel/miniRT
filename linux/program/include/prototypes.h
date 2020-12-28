/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 21:05:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "scene.h"

// Print function, remove when turning in

int	print_file(t_scene *scene);

/*
** src/parsing/
*/

int		parse_file(char *pathname, t_scene *scene, t_mlx mlx);
int		parse_resolution(char **element, t_scene *scene, t_mlx mlx);
int		parse_camera(char **element, t_vect *cameras);
int		parse_sphere(char **element, t_vect *spheres);

/*
** parsing_utils
*/

int		check_information(char **element, int expected);
int		check_color(char *information);
int		check_coordinates(char *information);
int		check_number(char *information);
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

/*
** Vector Utilities
*/

t_vec3	vec_gen(double x, double y, double z);

/*
** Vector Operations
*/

t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_normalize(t_vec3 v);
double	vec_magnitude(t_vec3 v);
double	vec_dot(t_vec3 a, t_vec3 b);

#endif
