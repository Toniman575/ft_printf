/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:38:47 by asadik            #+#    #+#             */
/*   Updated: 2025/10/14 15:01:31 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

/// @brief Converts integer into its string representation.
/// @param n the integer being converted.
/// @return Returns dynamically allocated null-terminated string or
/// @return a null pointer if allocation fails.
char	*ft_itoa(int n)
{
	int		len;
	char	*string;
	int		current;

	len = get_len(n);
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[len] = '\0';
	if (n < 0)
		string[0] = '-';
	len--;
	while (n > 9 || n < -9)
	{
		current = n % 10;
		if (current < 0)
			current *= -1;
		string[len] = current + '0';
		n /= 10;
		len--;
	}
	if (n < 0)
		n *= -1;
	string[len] = n + '0';
	return (string);
}
