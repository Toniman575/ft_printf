/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:16:25 by asadik            #+#    #+#             */
/*   Updated: 2025/12/17 16:24:29 by asadik           ###   ########.fr       */
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

void	putnbr_base_16(unsigned long int n, char *base)
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
		ft_putchar_fd(base[current], 1);
		div /= 16;
	}
	ft_putchar_fd(base[n], 1);
}

int	p_pointer(unsigned long int ptr, int *length)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (!ptr)
		return (0);
	putnbr_base_16(ptr, base);
	return (1);
}


int	test2(int cursor, int *length, const char *str, va_list *list)
{
	if (str[cursor] == 'c')
		return (p_char(va_arg(*list, int)));
	else if (str[cursor] == 's')
		*length += p_string(va_arg(*list, long int), length);
	else if (str[cursor] == 'p')
		*length += p_pointer(va_arg(*list, unsigned long int), length);
	else if (str[cursor] == 'd' || str[cursor] == 'i')
		*length += p_integer(va_arg(*list, int), length);
	else if (str[cursor] == 'u')
		*length += p_integer(va_arg(*list, unsigned int), length);
	else if (str[cursor] == 'x')
		*length += p_hex_lower(va_arg(*list, unsigned int));
	else if (str[cursor] == 'X')
		*length += p_hex_upper(va_arg(*list, unsigned int));
	else if (str[cursor] == '%')
		write(1, "%%", 2);
	else
	{
		write(1, "%", 1);
		write(1, &str[cursor], 1);
	}
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
	return (cursor + length);
}

#include <stdio.h>
int main()
{
	printf("%p", -1235);
}