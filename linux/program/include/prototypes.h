/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/31 13:04:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "scene.h"

// Print function, remove when turning in

int	print_vec(t_vec3 a);
int		print_file(t_scene *scene);

/*
** argument_checks.c
*/

int		check_input(int argc, char *argv[]);

/*
** src/parsing/
*/

int		parse_file(char *pathname, t_scene *scene, t_mlx mlx);
int		parse_resolution(char **element, t_scene *scene, t_mlx mlx, t_found *bools);
int		parse_camera(char **element, t_vect *cameras, t_found *bools);
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
t_color	gen_color(int r, int g, int b);

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
** Intersection Functions
*/

int	ray_intersection(t_vec3 origin, t_vec3 direction, t_objects objects, t_intersection_data *data);
void	intersect_spheres(t_vec3 origin, t_vec3 direction, t_vect *spheres, t_intersection_data *data);
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
int		vec_equal(t_vec3 a, t_vec3 b);
int		vec_parallel(t_vec3 a, t_vec3 b);
t_space	new_coordinate_space(t_vec3 origin, t_vec3 base_z);

/*
** Vector Operations
*/

t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_normalize(t_vec3 v);
double	vec_magnitude(t_vec3 v);
double	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
t_vec3	vec_scalar(t_vec3 a, double scalar);
t_vec3	vec_divide(t_vec3 a, double s);
t_vec3	vec_dir(t_vec3 a, t_vec3 b);
double	vec_square(t_vec3 a);

/*
** Vector rotation
** Can probably be easier using matrices
*/

t_vec3	vec_rotate_x(t_vec3 a, double rad);
t_vec3	vec_rotate_y(t_vec3 a, double rad);
t_vec3	vec_rotate_z(t_vec3 a, double rad);

/*
** math_utils.c
*/

double	deg_to_rad(double degrees);
double	rad_to_deg(double radians);

#endif
