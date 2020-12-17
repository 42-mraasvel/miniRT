/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 22:00:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/17 22:07:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "libft.h"
// #include "minirt.h"

int	free_boys(void *mlx_ptr)
{
	free(mlx_ptr);
	return (0);
}

int	gen_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

void	put_pixel_to_image(t_img img, int x, int y, int color)
{
	unsigned int	*addr;

	addr = (unsigned int *)(img.addr + (y * img.size_line) + x * (img.bpp / 8));
	*addr = color;
}

int	mlx_test(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (ft_perror("mlx_init", mlx_error));

	win_ptr = mlx_new_window(mlx_ptr, X_WIN, Y_WIN, "Mini Window");
	if (win_ptr == NULL)
		return (free_boys(mlx_ptr));
	mlx_pixel_put(mlx_ptr, win_ptr, 5, 5, gen_color(0, 255, 0));

	img.img_ptr = mlx_new_image(mlx_ptr, 200, 200);
	if (win_ptr == NULL)
		return (free_boys(mlx_ptr));
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	put_pixel_to_image(img, 6, 5, gen_color(255, 0, 0));
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, img.img_ptr);

	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}

int	main(void)
{
	printf("lol\n");
	mlx_test();
	return (0);
}
