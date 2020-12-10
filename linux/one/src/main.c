/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/10 13:16:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "minirt.h"

int	ft_strerror(int errnum)
{
	static const char	*error_table[] = {
		"Success",
		"Malloc Error",
		"Write Error" };

	if (printf("%s\n", error_table[errnum]) == -1)
		return (write_error);
	return (errnum);
}

int	call_draw_line(t_data *img)
{
	t_pair one, two;
	int	ret;

	one.x = 100; one.y = 250;
	two.x = 200; two.y = 500;
	ret = draw_line(one, two, img);
	if (ret != success)
		ft_strerror(ret);
	return (ret);
}

int	call_draw_triangle(t_data *img)
{
	t_triangle	triangle;
	int			ret;

	triangle.points[0].x = 300;
	triangle.points[0].y = 50;
	triangle.points[1].x = 100;
	triangle.points[1].y = 350;
	triangle.points[2].x = 1200;
	triangle.points[2].y = 500;
	draw_triangle(triangle, img);
	return (success);
}

typedef struct	s_vars
{
	void *mlx;
	void *win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key: %d\n", keycode);
}

int	start_mlx(void)
{
	t_vars vars;
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Mini.maaRTen");
	// img.img = mlx_new_image(vars.mlx, 1280, 720);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// for (int i = 0; i < 1280; i++)
	// {
	// 	for (int j = 0; j < 720; j++)
	// 	{
	// 		ft_pixel_put(&img, i, j, 0x00000000);
	// 	}
	// }
	// call_draw_triangle(&img);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (success);
}

int	main(void)
{
	start_mlx();
	return (0);
}
