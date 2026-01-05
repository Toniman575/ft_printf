/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:03 by asadik            #+#    #+#             */
/*   Updated: 2026/01/05 13:01:39 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_isprint(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *s);
int		ft_printf(const char *str, ...);
void	p_char(int arg, int *length);
void	p_string(unsigned long int ptr, int *length);
void	putnbr_base_16(unsigned long int n, char *base, int *length);
void	p_pointer(unsigned long int ptr, int *length);
void	p_integer(int nbr, int *length);
void	p_uinteger(unsigned int nbr, int *length);
void	p_hex_lower(unsigned int nbr, int *length);
void	p_hex_upper(unsigned int nbr, int *length);

#endif