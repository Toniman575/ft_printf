/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:42:24 by asadik            #+#    #+#             */
/*   Updated: 2026/01/07 10:36:08 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"
#include "libft/libft.h"

void	putnbr_base_16(unsigned long int n, char *base, int *length)
{
	long int	current;
	long int	div;

	div = 1;
	while (n / div > 15)
		div *= 16;
	while (div > 0)
	{
		current = n / div;
		n %= div;
		*length += 1;
		ft_putchar_fd(base[current], 1);
		div /= 16;
	}
}
