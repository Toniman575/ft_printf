/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:04:54 by asadik            #+#    #+#             */
/*   Updated: 2025/10/16 10:36:16 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/// Returns length of a string, including '\0'.
/// Given string must me null-terminated to avoid undefined behaviour.
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
