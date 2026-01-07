/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:28 by asadik            #+#    #+#             */
/*   Updated: 2026/01/07 10:35:05 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H
# include "libft/libft.h"

void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *s);
int		ft_printf(const char *str, ...);
void	p_char(int arg, int *length);
void	p_string(unsigned long int ptr, int *length);
void	p_pointer(unsigned long int ptr, int *length);
void	p_integer(int nbr, int *length);
void	p_uinteger(unsigned int nbr, int *length);
void	p_hex(unsigned int nbr, int *length, char *base);
void	putnbr_base_16(unsigned long int n, char *base, int *length);

#endif