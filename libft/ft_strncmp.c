/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:41:14 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 14:49:24 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/// Compares first n bytes of strings s1 and s2.
/// Returns int as follows:
///  - s1 == s2: 0;
///  - s1 < s2: negative value;
///  - s1 > s2: positive value;
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = (size_t) 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (!(us1[i] == '\0' && us2[i] == '\0') && i < n)
	{
		if (us1[i] != s2[i])
			return (us1[i] - us2[i]);
		i += (size_t) 1;
	}
	return (0);
}
