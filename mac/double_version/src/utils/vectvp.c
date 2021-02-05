/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vectvp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:51:51 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 17:58:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libvect.h"
#include "libft.h"

static void	*vectvp_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

t_vectvp	*vectvp_init(size_t initial_size)
{
	t_vectvp	*vectvp;

	if (initial_size == 0)
		initial_size = 2;
	vectvp = malloc(sizeof(t_vectvp));
	if (vectvp == NULL)
		return (NULL);
	vectvp->table = malloc(initial_size * sizeof(void*));
	if (vectvp->table == NULL)
	{
		free(vectvp);
		return (NULL);
	}
	vectvp->nmemb = 0;
	vectvp->size = initial_size;
	return (vectvp);
}

void		vectvp_free(t_vectvp *vectvp)
{
	size_t	i;

	i = 0;
	while (i < vectvp->nmemb)
	{
		free(vectvp->table[i]);
		i++;
	}
	free(vectvp->table);
	free(vectvp);
}

static int	vectvp_realloc(t_vectvp *vectvp)
{
	void	*new_table;

	vectvp->size *= 2;
	new_table = malloc(vectvp->size * sizeof(void*));
	if (new_table == NULL)
		return (-1);
	vectvp_memcpy(new_table, vectvp->table, vectvp->nmemb * sizeof(void*));
	free(vectvp->table);
	vectvp->table = new_table;
	return (0);
}

int			vectvp_pushback(t_vectvp *vectvp, void *data, size_t size)
{
	void	*new;

	if (vectvp->nmemb == vectvp->size)
	{
		if (vectvp_realloc(vectvp) == -1)
			return (-1);
	}
	new = (void*)malloc(size);
	if (new == NULL)
		return (-1);
	vectvp_memcpy(new, data, size);
	vectvp->table[vectvp->nmemb] = new;
	vectvp->nmemb += 1;
	return (0);
}
