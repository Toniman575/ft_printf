/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:48:23 by asadik            #+#    #+#             */
/*   Updated: 2025/10/14 15:28:13 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Creates a duplicate of input string s.
/// @param s The null-terminated string to be duplicated.
/// @return A pointer to the newly allocated string
char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		str_len;

	str_len = ft_strlen(s) + 1;
	new_str = malloc(str_len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, str_len);
	return (new_str);
}
