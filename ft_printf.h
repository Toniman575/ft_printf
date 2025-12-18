/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:03 by asadik            #+#    #+#             */
/*   Updated: 2025/12/18 14:05:07 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>

int		ft_isprint(int c);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int 	ft_printf(const char *str, ...);

#endif