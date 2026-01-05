/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:42:24 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 10:21:32 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_char(int arg)
{
	if (ft_isprint(arg))
	{
		ft_putchar_fd(arg, 1);
		return (1);
	}
	else
		return (0);
}

int	p_string(unsigned long int ptr, int *length)
{
	char	*string;

	string = (char *)ptr;
	if (string)
	{
		*length += ft_strlen(string);
		while (*string != '\0')
		{
			if (!ft_isprint(*string))
				return (0);
			ft_putchar_fd(*string, 1);
			string++;
		}
		return (1);
	}
	return (0);
}

void	putnbr_base_16(unsigned long int n, char *base, int *length)
{
	int	current;
	int	div;

	div = 1;
	while (n / div > 15)
		div *= 16;
	while (n > 15)
	{
		current = n / div;
		n %= div;
		*length += 1;
		ft_putchar_fd(base[current], 1);
		div /= 16;
	}
}
