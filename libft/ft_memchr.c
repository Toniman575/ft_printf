/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:11:58 by asadik            #+#    #+#             */
/*   Updated: 2025/10/05 17:27:30 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/// Scans initial n bytes of memory area pointed to by s for
/// first instance of c. Return pointer to matching
/// byte or NULL if character does not occur.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;
	unsigned char	c_cast;

	i = 0;
	s_cast = (unsigned char *)s;
	c_cast = (unsigned char)c;
	while (i < n)
	{
		if (*(s_cast + i) == c_cast)
			return (s_cast + i);
		i++;
	}
	return (0);
}
