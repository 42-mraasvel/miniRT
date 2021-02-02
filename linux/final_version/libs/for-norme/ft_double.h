/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:20:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 15:14:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H

typedef union				u_double
{
	double					value;
	struct					s_bits
	{
		unsigned long long	fraction : 52;
		unsigned int		exponent : 11;
		unsigned int		sign : 1;

	}						bits;
}							t_double;

#endif
