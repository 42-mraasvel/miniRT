/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvect.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:45:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 18:37:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# include <stddef.h>

typedef struct	s_vect
{
	void	*table;
	size_t	data_size;
	size_t	nmemb;
	size_t	size;
}				t_vect;

t_vect			*vect_init(size_t initial_size, unsigned int data_type);
int				vect_pushback(t_vect *vect, void *data);
void			vect_free(t_vect *vect, void (*del)(void*));

typedef struct	s_vectvp
{
	void	**table;
	size_t	nmemb;
	size_t	size;
}				t_vectvp;

t_vectvp		*vectvp_init(size_t initial_size);
int				vectvp_pushback(t_vectvp *vectvp, void *data, size_t size);
void			vectvp_free(t_vectvp *vectvp);

#endif
