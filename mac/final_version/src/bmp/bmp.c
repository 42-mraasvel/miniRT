/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 10:48:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 15:58:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "bmp.h"
#include "ft_error.h"
#include "render.h"

static t_img	*bmp_init_image(t_data *data)
{
	t_img	*new;

	new = (t_img*)malloc(1 * sizeof(t_img));
	if (new == NULL)
		return (NULL);
	new->bpp = 3;
	new->size_line = data->scene->resolution.x * new->bpp;
	new->height = data->scene->resolution.y;
	new->bmp = true;
	new->img_ptr = NULL;
	new->addr = (char*)malloc((new->size_line * new->height) * sizeof(char));
	if (new->addr == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

int				save_bmp(t_data *data)
{
	data->next_img = bmp_init_image(data);
	if (data->next_img == NULL)
		return (ft_error(data, malloc_error));
	if (next_frame(data) != success)
		return (ft_error(data, bmp_error));
	if (create_bmp_file(data) != success)
		return (ft_error(data, bmp_error));
	return (success);
}
