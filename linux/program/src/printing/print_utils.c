/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 13:14:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/17 13:18:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int get_max_len(t_m34 matrix)
{
    int i, j;
    int max_len, len;
    i = 0;
    max_len = 0;
    while (i < 3) {
        j = 0;
        while (j < 4) {
            len = ft_numlen_dbl(matrix.m[i][j]);
            if (matrix.m[i][j] < 0)
                len++;
            max_len = ft_max(max_len, len);
            j++;
        }
        i++;
    }
    return (max_len);
}
void print_matrix(t_m34 matrix)
{
    int i, j;
    int max_len;
    i = 0;
    max_len = get_max_len(matrix) + 2;
    while (i < 3) {
        j = 0;
        ft_printf("|");
        while (j < 4) {
            if (j != 0)
                ft_printf(" ");
            ft_printf("%*.1f", max_len, matrix.m[i][j]);
            j++;
        }
        ft_printf("|\n");
        i++;
    }
    ft_printf("\n");
}
