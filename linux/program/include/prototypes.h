/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/27 22:16:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "minirt.h"
# include "objects.h"
# include "scene.h"

/*
** parse.c
*/

int		parse_file(char *pathname, t_scene *scene);

/*
** scene.c
*/

int		init_scene(t_scene *scene);
void	free_scene(t_scene scene);

/*
** error.c
*/

int		ft_perror(char *argument, t_errnums error_type);

#endif
