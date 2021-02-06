/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 21:05:08 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 11:45:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_error.h"
#include "parsing.h"
#include "minirt.h"

static int	jump_func(t_scene *scene, char **element, t_parsers jump[])
{
	int	i;

	i = 0;
	while (i < PARSE_FUNCTIONS)
	{
		if (ft_strcmp(jump[i].id, element[0]) == 0)
			return (jump[i].parser(scene, element));
		i++;
	}
	return (parse_error);
}

static int	extract_information(t_scene *scene, char *line, t_parsers jump[])
{
	char	**element;
	int		ret;

	if (*line == '\0')
		return (success);
	element = ft_split_set(line, " \t");
	if (element == NULL)
		return (malloc_error);
	if (element[0] != NULL)
		ret = jump_func(scene, element, jump);
	else
		ret = parse_error;
	ft_free_split(element);
	return (ret);
}

/*
** Array of key + parse function pointers pairs
*/

static void	init_jump_table(t_parsers (*jump)[])
{
	ft_strlcpy((*jump)[0].id, "R", 2);
	(*jump)[0].parser = &parse_resolution;
	ft_strlcpy((*jump)[1].id, "A", 2);
	(*jump)[1].parser = &parse_ambient;
	ft_strlcpy((*jump)[2].id, "c", 2);
	(*jump)[2].parser = &parse_camera;
	ft_strlcpy((*jump)[3].id, "l", 2);
	(*jump)[3].parser = &parse_light;
	ft_strlcpy((*jump)[4].id, "sp", 3);
	(*jump)[4].parser = &parse_sphere;
	ft_strlcpy((*jump)[5].id, "pl", 3);
	(*jump)[5].parser = &parse_plane;
	ft_strlcpy((*jump)[6].id, "sq", 3);
	(*jump)[6].parser = &parse_square;
	ft_strlcpy((*jump)[7].id, "cy", 3);
	(*jump)[7].parser = &parse_cylinder;
	ft_strlcpy((*jump)[8].id, "tr", 3);
	(*jump)[8].parser = &parse_triangle;
}

static int	read_file(t_scene *scene, int fd)
{
	int			ret;
	int			ret2;
	char		*line;
	t_parsers	jump_table[PARSE_FUNCTIONS];

	ret = 1;
	init_jump_table(&jump_table);
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (parse_error);
		ret2 = extract_information(scene, line, jump_table);
		free(line);
		if (ret2 != success)
			return (ret2);
	}
	return (success);
}

int			parse_file(t_data *data, char *pathname)
{
	int	fd;
	int	ret;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (ft_error(data, parse_error));
	ret = read_file(data->scene, fd);
	close(fd);
	if (ret != success)
		return (ft_error(data, ret));
	if (!valid_data(data))
		return (ft_error(data, parse_error));
	return (success);
}
