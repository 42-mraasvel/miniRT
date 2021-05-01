/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   headers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:06:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/17 14:27:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

#include "structs.h"

#define X 1280
#define Y 720
#define WINNAME "MiniLibx"

typedef enum e_errnums
{
	fail,
	success
} t_errnums;

int mlx_wrapper(t_mlx *mlx);
void activate_hooks(t_data *data);
void exit_program(t_data *data);
t_img *get_mlx_image(t_data *data, int x, int y);
t_vec2 vec_gen(int x, int y);
t_square *create_square(t_vec2 center, int size, t_col color);
t_col get_color(int r, int g, int b);
t_col random_color(void);
int next_frame(t_data *data);
void ft_pixel_put(t_img *img, int x, int y, t_col color);
void translate_square(void *object, t_vec2 translation);
t_bool move_obj(int keycode, void *object);


#endif
