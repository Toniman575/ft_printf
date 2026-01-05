/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:27:03 by asadik            #+#    #+#             */
/*   Updated: 2025/10/12 13:49:07 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// Converts initial string to an int skipping leading whitespace
/// characters and handling an optional '+' or '-' sign.
/// Processes numeric chars until a non-digit is encountered and
/// returns the resulting integer, accounting for negative values if applicable.
int	ft_atoi(const char *nptr)
{
	int	number;
	int	negative;

	number = 0;
	negative = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		negative = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		number *= 10;
		number += *nptr - '0';
		nptr++;
	}
	if (negative)
		number *= negative;
	return (number);
}
