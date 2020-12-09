/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:52:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/28 22:40:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
** 0 adds no shade, while 1 will make the color completely dark.
** 0.5 will dim it halfway. etc
*/

// int	add_shade(double distance, int color)
// {
// }

/*
** Invert the color.
** 255 - T/R/G/B = new T/R/G/B
*/

int	get_opposite(int color)
{
	return (create_trgb(255 - (color >> 24), 255 - ((color >> 16) & 0xFF),
	255 - ((color >> 8) & 0xFF), 255 - (color & 0xFF)));
}
