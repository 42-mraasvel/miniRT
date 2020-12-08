/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 13:45:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/08 13:49:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*ptr;
	char	str[] = "NIOPWIZ";

	printf("val: %d\n", (unsigned char)(512));
	ptr = memchr(str, 'Z' + 256, strlen(str) + 1);
	printf("%p\n", ptr);
	return (0);
}
