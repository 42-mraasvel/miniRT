/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 20:50:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 12:46:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	print_vec(t_vec3 a)
{
	return (ft_printf("%.2f,%.2f,%.2f", a.x, a.y, a.z));
}

int	print_color(t_color a)
{
	return (ft_printf("%d,%d,%d", a.rgb.r, a.rgb.g, a.rgb.b));
}

int	print_resolution(t_resolution resolution)
{
	return (ft_printf("R\t%d\t%d\n\n", resolution.x, resolution.y));
}

int	print_cameras(t_vect *cameras)
{
	size_t		i;
	t_camera	c;

	i = 0;
	while (i < cameras->nmemb)
	{
		c = ((t_camera*)cameras->table)[i];
		ft_printf("c\t");
		if (print_vec(c.position) < 16)
			ft_printf("\t");
		ft_printf("\t");
		print_vec(c.orientation);
		ft_printf("\t%.2f\n", c.fov);
		i++;
	}
	ft_printf("\n");
	return (success);
}

int	print_spheres(t_vect *spheres)
{
	size_t		i;
	t_sphere	s;

	i = 0;
	while (i < spheres->nmemb)
	{
		s = ((t_sphere*)spheres->table)[i];
		ft_printf("sp\t");
		if (print_vec(s.position) < 16)
			ft_printf("\t");
		ft_printf("\t%.2f\t", s.diameter);
		print_color(s.color);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	return (success);
}

int	print_file(t_scene *scene)
{
	ft_printf("FILE DATA:\n\n");
	print_resolution(scene->resolution);
	print_cameras(scene->cameras);
	print_spheres(scene->objects.spheres);
	return (success);
}
