/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 14:56:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "scene.h"

// Print function, remove when turning in

int		print_file(t_scene *scene);

/*
** argument_checks.c
*/

int		check_input(int argc, char *argv[]);

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
** hooks.c
*/

int		expose_hook(t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);

/*
** mlx_util.c
*/

void	ft_pixel_put(t_img img, int x, int y, t_color color);

/*
** init_image.c
*/

t_img	*init_image(t_data *data);
int		next_frame(t_data *data);

/*
** render_image.c
*/

int		render_image(t_scene *scene, t_img *img, t_camera camera);

/*
** error.c
*/

int		ft_perror(char *argument, t_errnums error_type);

/*
** Free Functions
*/

void	free_program(t_data data, int status);
void	free_image(void *mlx_ptr, t_img *img);
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
