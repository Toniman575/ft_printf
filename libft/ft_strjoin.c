/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:29:03 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 11:00:22 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Concatenates strings s1 and s2. Uses ft_strlen and malloc to
/// @brief allocate memory for the combined string. Uses ft_strlcpy and
/// @brief ft_strlcat to copy the combined string to the allocated memory
/// @brief region.
/// @return Resulting combined string or a nullpointer if allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	s1_len = (size_t)ft_strlen(s1);
	s2_len = (size_t)ft_strlen(s2);
	new_str = ft_calloc((s1_len + s2_len + (size_t)1), sizeof(char));
	if (new_str == 0)
		return (0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}
