/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:03:17 by asadik            #+#    #+#             */
/*   Updated: 2025/10/08 15:56:14 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/// @brief Trims characters defined in string set from start and
/// @brief end of string s1. Keeps going from both directions until character
/// @brief not in set is encountered.
/// @param s1 The null-terminated string being trimmed.
/// @param set Null-terminated string of characters we search for in s1.
/// @return Newly allocated string, trimmed version of s1.
/// @return If s1 or set is 0, or allocation fails, returns 0.
/// @see ft_strlcpy
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	new_len;
	char	*result;

	if (!s1 || !set)
		return (0);
	first = 0;
	while (s1[first] && check_set(s1[first], set))
		first++;
	last = ft_strlen(s1);
	while (last > first && check_set(s1[last - 1], set))
		last--;
	new_len = last - first;
	result = (char *)malloc(new_len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + first, new_len + 1);
	return (result);
}
