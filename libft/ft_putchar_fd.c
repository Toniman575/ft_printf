/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:00:33 by asadik            #+#    #+#             */
/*   Updated: 2025/12/17 12:13:57 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/// @brief Writes a character to the given filedescriptor.
/// @param c the character to be written.
/// @param fd the filedescriptor written to.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
