/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:50:46 by asadik            #+#    #+#             */
/*   Updated: 2025/10/14 15:15:43 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/// @brief Copies bytes from one memory area to another.
/// @brief Handles overlapping memory regions by determining
/// @brief the appropriate direction of copying.
/// @param dest points to the memory area being copied to.
/// @param src points to the memory area being copied from.
/// @param n determines how many bytes should be copied.
/// @return Returns dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (const char *) src;
	d = (char *) dest;
	if (s <= d)
	{
		i = n - 1;
		while (i <= n)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
