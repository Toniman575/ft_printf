/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:15:15 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 09:07:26 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Writes an integer to the given filedescriptor.
/// @param n the integer to be written.
/// @param fd the filedescriptor written to.
void	ft_putnbr_fd(int n, int fd)
{
	int	current;
	int	div;

	if (n < 0)
		ft_putchar_fd('-', fd);
	div = 1;
	while (n / div > 9 || n / div < -9)
		div *= 10;
	while (div > 0)
	{
		current = n / div;
		if (current < 0)
			current *= -1;
		n %= div;
		ft_putchar_fd(current + '0', fd);
		div /= 10;
	}
}
