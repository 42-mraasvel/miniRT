/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:20:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 13:47:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H

# include "stdint.h"

typedef union		u_double
{
	double			value;
	struct			s_bitfield
	{
		uint64_t	mantissa : 52;
		uint16_t	exponent : 11;
		uint8_t		sign : 1;
	}				bits;
}					t_double;

#endif
