/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:16:25 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 11:57:40 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	coordinator(int cursor, int *length, const char *str, va_list *list)
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
			if (!coordinator(cursor + 1, &length, str, &list))
				return (-1);
			cursor += 2;
		}
	}
	return (va_end(list), length);
}
