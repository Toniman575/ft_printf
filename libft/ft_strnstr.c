/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:28:13 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 14:58:39 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// Searches for first occurrence of little in first len chars of big.
/// Returns *char as follows:
///  - little is empty: *big;
///  - little not found in big: 0; 
///  - little found in big: first *char of little found in big;
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = (size_t) 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (i + little_len <= len && big[i] != '\0')
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)(big + i));
		i += (size_t) 1;
	}
	return (0);
}
