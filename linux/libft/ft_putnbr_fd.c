/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:23:35 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 23:54:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_fd_output(unsigned int n, int fd)
{
	char	c;

	if (n != 0)
	{
		c = n % 10 + '0';
		ft_putnbr_fd_output(n / 10, fd);
		if (write(fd, &c, 1) == -1)
			return ;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return ;
		return ;
	}
	if (n < 0)
		if (write(fd, "-", 1) == -1)
			return ;
	if (n < 0)
		n = -n;
	ft_putnbr_fd_output(n, fd);
}
