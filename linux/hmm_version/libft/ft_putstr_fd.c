/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:13:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 23:54:19 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == 0 || *s == 0)
		return ;
	i = 0;
	while (s[i] != 0)
		i++;
	if (write(fd, s, i) == -1)
		return ;
}
