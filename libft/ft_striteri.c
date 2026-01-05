/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:35:28 by asadik            #+#    #+#             */
/*   Updated: 2025/10/12 11:49:56 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Takes a string and applies the supplied function onto each character.
/// @param s the string to be manipulated.
/// @param f the function taking a pointer and index of each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
