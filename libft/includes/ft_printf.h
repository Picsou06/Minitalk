/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:42:41 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:23:00 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

int		callfunction(char c, va_list ptr);
int		ft_printf(const char *chaine, ...);
int		ft_ptr_len(uintptr_t num);
int		ft_count_hex(unsigned long n);
int		ft_nb_len(int nb);
int		ft_unsignednb_len(unsigned int nb);
void	ft_puthex_lower(unsigned int n);
void	ft_puthex_toupper(unsigned int n);
void	ft_puthex(unsigned long n);
void	ft_putptr(void *ptr);

#endif