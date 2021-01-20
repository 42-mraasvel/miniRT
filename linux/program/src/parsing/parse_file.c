/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:27:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/20 13:17:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "libftprintf.h"
#include "prototypes.h"

/*
** Since every string has to be error-checked
** we might as well create a chain of if-else statements right?
*/

static int	parse_jump(char **element, t_scene *scene, t_mlx mlx, t_found *bools)
{
	if (ft_strcmp(element[0], "R") == 0)
		return (parse_resolution(element, scene, mlx, bools));
	else if (ft_strcmp(element[0], "A") == 0)
		;
	else if (ft_strcmp(element[0], "c") == 0)
		return (parse_camera(element, scene->cameras, bools));
	else if (ft_strcmp(element[0], "l") == 0)
		;
	else if (ft_strcmp(element[0], "sp") == 0)
		return (parse_sphere(element, scene->objects.spheres));
	else if (ft_strcmp(element[0], "pl") == 0)
		return (parse_plane(element, scene->objects.planes));
	else if (ft_strcmp(element[0], "sq") == 0)
		return (parse_square(element, scene->objects.squares));
	else if (ft_strcmp(element[0], "cy") == 0)
		return (parse_cylinder(element, scene->objects.cylinders));
	else if (ft_strcmp(element[0], "tr") == 0)
		return (parse_triangle(element, scene->objects.triangles));
	return (file_error);
}

static int	parse_information(char *line, t_scene *scene, t_mlx mlx, t_found *bools)
{
	char	**element;
	int		ret;

	element = ft_split_set(line, " \t\n\r\v\f");
	if (element == NULL)
		return (malloc_error);
	ret = success;
	if (*element != NULL)
	{
		ret = parse_jump(element, scene, mlx, bools);
		if (ret != success)
		{
			if (ft_printf("Parse Error:\n|%s|\n", line) == -1)
				ret = write_error;
		}
	}
	ft_free_split(element);
	return (ret);
}

static int	read_file(int fd, t_scene *scene, t_mlx mlx)
{
	int		ret;
	int		parse_ret;
	char	*line;
	t_found	bools;

	ret = 1;
	ft_bzero(&bools, sizeof(bools));
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (gnl_error);
		// remove hashtag check
		if (*line != '\0' && *line != '#')
		{
			parse_ret = parse_information(line, scene, mlx, &bools);
			if (parse_ret != success)
			{
				free(line);
				return (parse_ret);
			}
		}
		free(line);
	}
	if (bools.resolution == 0 || bools.camera == 0)
		return (file_error);
	return (success);
}

/*
** 1. Initialize all arrays in the scene.
** 2. Read in file line by line, one element for each line.
*/

int			parse_file(char *pathname, t_scene *scene, t_mlx mlx)
{
	int	fd;
	int	ret;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (ft_perror(pathname, open_error));
	if (init_scene(scene) != success)
		return (ft_perror(NULL, malloc_error));
	ret = read_file(fd, scene, mlx);
	if (ret != success)
		ft_perror(NULL, ret);
	close(fd);
	return (ret);
}
