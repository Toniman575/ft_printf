/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:56:56 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 10:43:48 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	get_length(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	length;

	i = 0;
	x = 0;
	while (dest[x] != '\0')
		x++;
	while (src[i] != '\0')
		i++;
	if (x > size)
		length = i + size;
	else
		length = x + i;
	return (length);
}

/// @brief Appends size characters from string src to string dst.
/// @brief Always ensures result is null-terminated.
/// @return Total length of resulting string.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	length;

	length = get_length(dst, src, size);
	if (size == 0)
		return (length);
	i = 0;
	x = 0;
	while (dst[i] != '\0')
		i++;
	while (src[x] != '\0' && i + 1 < size)
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (length);
}
