/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 21:02:08 by mraasvel      ########   odam.nl         */
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

	one.x = 0; one.y = 250;
	two.x = 125; two.y = 0;
	ret = draw_line(one, two, img);
	if (ret != success)
		ft_strerror(ret);
	return (ret);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1280, 720, "MLX Window");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 1280; i++)
	{
		for (int j = 0; j < 720; j++)
		{
			ft_pixel_put(&img, i, j, 0x00FFFFFF);
		}
	}
	call_draw_line(&img);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	free(mlx);
	return (0);
}
