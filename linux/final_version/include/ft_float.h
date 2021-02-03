/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 22:41:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 22:43:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <stdint.h>

typedef union	u_float
{
	float	val;
	struct		s_bitfield
	{
		uint32_t	fraction : 23;
		uint16_t	exponent : 8;
		uint8_t		sign : 1;
	}		bits;
}				t_float;

#endif
