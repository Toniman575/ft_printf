/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:16:25 by asadik            #+#    #+#             */
/*   Updated: 2025/12/18 14:29:25 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
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
	*length += 1;
	ft_putchar_fd(base[n], 1);
}

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

void p_hex_lower(unsigned int nbr, int *length)
{
	putnbr_base_16(nbr, "0123456789abcdef", length);
}

void p_hex_upper(unsigned int nbr, int *length)
{
	putnbr_base_16(nbr, "0123456789ABCDEF", length);
}

int	test2(int cursor, int *length, const char *str, va_list *list)
{
	if (str[cursor] == 'c')
		return (p_char(va_arg(*list, int)));
	else if (str[cursor] == 's')
		return (p_string(va_arg(*list, long int), length));
	else if (str[cursor] == 'p')
		p_pointer(va_arg(*list, unsigned long int), length);
	else if (str[cursor] == 'd' || str[cursor] == 'i')
		p_integer(va_arg(*list, int), length);
	else if (str[cursor] == 'u')
		p_uinteger(va_arg(*list, unsigned int), length);
	else if (str[cursor] == 'x')
		p_hex_lower(va_arg(*list, unsigned int), length);
	else if (str[cursor] == 'X')
		p_hex_upper(va_arg(*list, unsigned int), length);
	else if (str[cursor] == '%')
		write(1, "%%", 2);
	else
	{
		write(1, "%", 1);
		write(1, &str[cursor], 1);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int cursor;
	int length;
	va_list list;
	
	cursor = 0;
	length = 0;
	va_start(list, str);
	if (!str)
		return (-1);
	while (str[cursor])
	{
		if (str[cursor] != '%')
		{
			write(1, &str[cursor], 1);
			cursor++;
		}
		else{
			if (!test2(cursor + 1, &length, str, &list))
				return (-1);
			cursor += 2;
		}
	}
	write(1, 0, 1);
	va_end(list);
	return (cursor + length);
}

#include <stdio.h>
#include <limits.h>
int main()
{
	//char *test = "asd";
	ft_printf("%d\n", 100005);

}