/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:58:11 by asadik            #+#    #+#             */
/*   Updated: 2025/10/05 17:27:34 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/// Compares first n bytes of memory areas s1 and s2.
/// Returns int as follows:
///  - s1 == s2: 0;
///  - s1 < s2: negative value;
///  - s1 > s2: positive value;
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	i = 0;
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_cast[i] != s2_cast[i])
			return (s1_cast[i] - s2_cast[i]);
		i++;
	}
	return (0);
}
