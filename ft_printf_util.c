/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:42:24 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 13:44:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
