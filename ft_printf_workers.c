/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_workers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:54:35 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 15:00:09 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf_util.h"

void	p_pointer(unsigned long int ptr, int *length)
{
	if (!ptr)
	{
		*(length) += 5;
		write(1, "(nil)", 5);
	}
	else
	{
		*(length) += 2;
		write(1, "0x", 2);
		putnbr_base_16(ptr, "0123456789abcdef", length);
	}
}

void	p_integer(int nbr, int *length)
{
	int	current;
	int	div;

	if (nbr < 0)
	{
		*length += 1;
		ft_putchar_fd('-', 1);
	}
	div = 1;
	while (nbr / div > 9 || nbr / div < -9)
		div *= 10;
	while (div > 0)
	{
		current = nbr / div;
		if (current < 0)
			current = -current;
		nbr %= div;
		*length += 1;
		ft_putchar_fd(current + '0', 1);
		div /= 10;
	}
}

void	p_uinteger(unsigned int nbr, int *length)
{
	int	current;
	int	div;

	div = 1;
	while (nbr / div > 9)
		div *= 10;
	while (div > 0)
	{
		current = nbr / div;
		nbr %= div;
		*length += 1;
		ft_putchar_fd(current + '0', 1);
		div /= 10;
	}
}

void	p_char(int arg, int *length)
{
	ft_putchar_fd((unsigned char)arg, 1);
	(*length)++;
}

void	p_string(unsigned long int ptr, int *length)
{
	char	*string;

	if (!ptr)
	{
		ft_putstr_fd("(null)", 1);
		(*length) += 6;
	}
	else
	{
		string = (char *)ptr;
		*length += ft_strlen(string);
		ft_putstr_fd(string, 1);
	}
}
