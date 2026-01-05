/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:00:05 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 15:27:56 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Uses ft_strlcpy to copy a substr from s starting at index start.
/// @return Resulting substring or a nullpointer if allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sub_len;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	sub_len = ft_strlen(s) - (size_t) start;
	if (sub_len > len)
		sub_len = len;
	substr = ft_calloc(sub_len + 1, sizeof(char));
	if (substr == 0)
		return (0);
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}
