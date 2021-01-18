**Linux Setup:**

	https://github.com/ilkou/minilibx

Compilation (Linux):

	xorg, x11 and zlib
	Libraries : -lmlx_linux -lXext -lX11 -lz -lm
	Includes : mlx.h in mlx_linux folder

Colors:

	Integer format: 0xTTRRGGBB
		T: Transparency
		R: Red color
		G: Green Color
		B: Blue color

Initialization:

	1. include <mlx.h> header to access all the functions
	2. <mlx_init> function returns a void* to current MLX instance

Error Handling:

	free(mlx_ptr) ?
	mlx_destroy_display(mlx_ptr);
	mlx_destroy_image(img_ptr);
	mlx_destroy_window(win_ptr); (only if mlx_loop wasn't called?)

	MLX functions that return NULL on error:

		1. mlx_init();
		2. mlx_new_window();
		3. mlx_new_image();
		4. mlx_xpm_to_image();
		5. mlx_xpm_file_to_image();


Tutorials:

https://github.com/ilkou/minilibx - Linux/WSL setup tutorial

https://harm-smits.github.io/42docs/libs/minilibx/ - Tutorial on using minilibx by hsmits

https://qst0.github.io/ft_libgfx/man_mlx.html
