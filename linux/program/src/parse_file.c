/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:27:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/27 23:21:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** Since every string has to be error-checked
** we might as well create a chain of if-else statements right?
*/

static int	parse_jump(char **element, t_scene *scene)
{
	if (ft_strcmp(element[0], "R") == 0)
		;
	else if (ft_strcmp(element[0], "A") == 0)
		;
	else if (ft_strcmp(element[0], "c") == 0)
		;
	else if (ft_strcmp(element[0], "l") == 0)
		;
	else if (ft_strcmp(element[0], "sp") == 0)
		;
	else if (ft_strcmp(element[0], "pl") == 0)
		;
	else if (ft_strcmp(element[0], "sq") == 0)
		;
	else if (ft_strcmp(element[0], "cy") == 0)
		;
	else if (ft_strcmp(element[0], "tr") == 0)
		;
	return (file_error);
}

static int	parse_information(char *line, t_scene *scene)
{
	char	**element;
	int		ret;

	element = ft_split(line, ' ');
	if (element == NULL)
		return (malloc_error);
	ret = parse_jump(element, scene);
	ft_free_split(element);
	return (ret);
}

static int	read_file(int fd, t_scene *scene)
{
	int		ret;
	int		parse_ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (gnl_error);
		if (*line != '\0')
		{
			parse_ret = parse_information(line, scene);
			if (parse_ret != success)
			{
				free(line);
				return (parse_ret);
			}
		}
		free(line);
	}
	return (success);
}

/*
** 1. Initialize all arrays in the scene.
** 2. Read in file line by line, one element for each line.
*/

int			parse_file(char *pathname, t_scene *scene)
{
	int	fd;
	int	ret;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (ft_perror(pathname, open_error));
	if (init_scene(scene) != success)
		return (ft_perror(NULL, malloc_error));
	ret = read_file(fd, scene);
	if (ret != success)
	{
		close(fd);
		free_scene(*scene);
		return (ft_perror(NULL, ret));
	}
	close(fd);
	return (success);
}
