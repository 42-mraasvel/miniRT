/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_util.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 17:02:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTIL_H
# define MATH_UTIL_H

# include <math.h>

/*
** This way there is only one division.
** Even though the compiled probably does that
** automatically.
*/

# define DTR ((double)(M_PI / 180.0))
# define RTD ((double)(180.0 / M_PI))

#endif
