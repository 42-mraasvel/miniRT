/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:11:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/18 17:46:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "key_linux.h"
#include "mlx.h"
#include "headers.h"
#include "x_events.h"

int mlx_wrapper(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (fail);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, X, Y, WINNAME);
	if (mlx->win_ptr == NULL)
		return (fail);
	return (success);
}

static void *abort_img(void *mlx, t_img *img, int pos)
{
	if (pos > 1)
		mlx_destroy_image(mlx, img->img_ptr);
	if (pos > 0)
		free(img);
}

t_img *get_mlx_image(t_data *data, int x, int y)
{
	t_img *img;

	img = malloc(1 * sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, x, y);
	if (img->img_ptr == NULL)
		return (abort_img(data->mlx->mlx_ptr, img, 1));
	img->addr = mlx_get_data_addr(
		img->img_ptr,
		&img->bpp,
		&img->size_line,
		&img->endian
	);
	if (img->addr == NULL)
		return (abort_img(data->mlx->mlx_ptr, img, 2));
	return (img);
}

void ft_pixel_put(t_img *img, int x, int y, t_col color)
{
	char *addr;

	if (y < 0 || y > Y)
		return ;
	if (x < 0)
		x = X + x;
	else if (x > X)
		x = x - X;
	addr = img->addr + y * img->size_line + x * img->bpp / 8;
	*(int*)addr = color.color;
}

void next_color(void *obj)
{
	((t_square*)obj)->color = random_color();
}


/* Hook functions */

int destroy_event(t_data *data)
{
	printf("Red cross exit.\n");
	exit_program(data);
}

int key_press(int keycode, t_data *data)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == K_ESC)
		exit_program(data);
	if (keycode == K_N) {
		next_color(data->obj);
		// next_frame(data);
	}
	move_obj(keycode, data->obj);
}

int key_press_hook(int keycode, t_data *data)
{
	printf("Hook - Keycode: %d\n", keycode);
	if (keycode == K_ESC)
		exit_program(data);
	if (keycode == K_N) {
		next_color(data->obj);
	}
	move_obj(keycode, data->obj);
}

int button_press(int keycode, int x, int y, t_data *data)
{
	printf("Button pressed %d: (%d, %d)\n", keycode, x, y);
	if (keycode == M_CLK_L)
	{
		if (data->obj != NULL)
			free(data->obj);
		data->obj = (void*)create_square(vec_gen(x, y), 200, random_color());
		if (data->obj == NULL)
			exit_program(data);
	}
}

void activate_hooks(t_data *data)
{
	//! ClientMessage is WSL-only for me (segfault on mac)
	mlx_hook(data->mlx->win_ptr, ClientMessage, NoEventMask, destroy_event, data);
	// mlx_key_hook(data->mlx->win_ptr, key_press, data);
	mlx_hook(data->mlx->win_ptr, ButtonPress, ButtonPressMask, button_press, data);
	//! Doesn't work on WSL, works on linux though
	mlx_hook(data->mlx->win_ptr, KeyPress, KeyPressMask, key_press_hook, data);
}
