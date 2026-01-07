/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:16:25 by asadik            #+#    #+#             */
/*   Updated: 2026/01/07 10:36:04 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_util.h"

static void	coordinator(int cursor, int *length, const char *str, va_list *list)
{
	if (str[cursor] == 'c')
		p_char(va_arg(*list, int), length);
	else if (str[cursor] == 's')
		p_string(va_arg(*list, long int), length);
	else if (str[cursor] == 'p')
		p_pointer(va_arg(*list, unsigned long int), length);
	else if (str[cursor] == 'd' || str[cursor] == 'i')
		p_integer(va_arg(*list, int), length);
	else if (str[cursor] == 'u')
		p_uinteger(va_arg(*list, unsigned int), length);
	else if (str[cursor] == 'x')
		putnbr_base_16(va_arg(*list, unsigned int), "0123456789abcdef", length);
	else if (str[cursor] == 'X')
		putnbr_base_16(va_arg(*list, unsigned int), "0123456789ABCDEF", length);
	else if (str[cursor] == '%')
	{
		write(1, "%", 1);
		(*length) += 1;
	}
	else
	{
		write(1, "%", 1);
		write(1, &str[cursor], 1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		cursor;
	int		length;
	va_list	list;

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
			length++;
		}
		else
		{
			coordinator(cursor + 1, &length, str, &list);
			cursor += 2;
		}
	}
	return (va_end(list), length);
}
