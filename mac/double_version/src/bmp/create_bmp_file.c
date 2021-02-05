/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_bmp_file.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 10:56:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 20:28:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "ft_enum.h"
#include "unistd.h"
#include "fcntl.h"

static int	file_size(t_data *data)
{
	return (data->scene->resolution.x * data->scene->resolution.y * 3 + 54);
}

static int	write_header(int fd, t_data *data)
{
	char	header[54];

	ft_bzero((void*)header, 54);
	header[0] = 'B';
	header[1] = 'M';
	*((int*)(header + 2)) = file_size(data);
	*((int*)(header + 10)) = 54;
	*(int*)(header + 14) = 40;
	*(int*)(header + 18) = data->scene->resolution.x;
	*(int*)(header + 22) = data->scene->resolution.y;
	*(short*)(header + 26) = 1;
	*(short*)(header + 28) = 24;
	*(int*)(header + 38) = data->scene->resolution.x;
	*(int*)(header + 42) = data->scene->resolution.y;
	if (write(fd, header, 54) == -1)
		return (bmp_error);
	return (success);
}

int			create_bmp_file(t_data *data)
{
	int	fd;

	fd = open("image.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		return (bmp_error);
	if (write_header(fd, data) != success)
		return (bmp_error);
	if (write(fd, data->next_img->addr, file_size(data) - 54) == -1)
		return (bmp_error);
	return (success);
}
