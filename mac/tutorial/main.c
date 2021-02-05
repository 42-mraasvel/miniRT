/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 09:28:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 17:20:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mlx.h"

#define X 1280
#define Y 720

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		height;
	int		endian;
}				t_img;

typedef struct	s_data
{
	t_mlx	*mlx;
	t_img	*curr_img;
}				t_data;

typedef enum	e_errnum
{
	success,
	error,
	mlx_error,
	malloc_error
}				t_errnum;

void exit_program(t_data *data)
{
	if (data->mlx != NULL && data->mlx->mlx_ptr != NULL) {
		// mlx_destroy_display(data->mlx->mlx_ptr);
		// free(data->mlx->mlx_ptr);
	}
	return ;
}

int	ft_perror(t_errnum type)
{
	static const char *table[] = {
		"Success",
		"Error",
		"MLX Error",
		"Malloc Error"
	};

	printf("%s\n", table[type]);
	return (type);
}

int abort_image(t_data *data, int pos, t_errnum type)
{
	if (pos >= 2)
		mlx_destroy_image(data->mlx->mlx_ptr, data->curr_img->img_ptr);
	if (pos >= 1)
		free(data->curr_img);
	return (ft_perror(type));
}

int init_images(t_data *data)
{
	data->curr_img = malloc(1 * sizeof(t_img));
	if (data->curr_img == NULL)
		return (abort_image(data, 0, malloc_error));
	data->curr_img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, X, Y);
	if (data->curr_img == NULL)
		return (abort_image(data, 1, mlx_error));
	data->curr_img->addr = mlx_get_data_addr(
		data->curr_img->img_ptr,
		&data->curr_img->bpp,
		&data->curr_img->size_line,
		&data->curr_img->endian
	);
	if (data->curr_img->addr == NULL)
		return (abort_image(data, 2, mlx_error));
	return (success);
}

int	initialize_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (ft_perror(mlx_error));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, X, Y, "Window");
	if (mlx->win_ptr == NULL)
		return (ft_perror(mlx_error));
	return (success);
}

int main(void)
{
	t_mlx	mlx;
	t_data	data;

	bzero(&mlx, sizeof(t_mlx));
	bzero(&data, sizeof(t_data));
	data.mlx = &mlx;
	initialize_mlx(&mlx);
	init_images(&data);
	// mlx_loop(data.mlx->mlx_ptr);
	return (0);
}
