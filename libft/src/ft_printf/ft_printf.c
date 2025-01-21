/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:51:58 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:32:41 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunsignednbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

int	callfunction2(char c, va_list ptr)
{
	unsigned int	uint_element;

	if (c == 'u')
	{
		uint_element = va_arg(ptr, unsigned int);
		ft_putunsignednbr_fd(uint_element, 1);
		return (ft_unsignednb_len(uint_element));
	}
	else if (c == 'x')
	{
		uint_element = va_arg(ptr, unsigned int);
		ft_puthex_lower(uint_element);
		return (ft_count_hex(uint_element));
	}
	else if (c == 'X')
	{
		uint_element = va_arg(ptr, unsigned int);
		ft_puthex_toupper(uint_element);
		return (ft_count_hex(uint_element));
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	callfunction(char c, va_list ptr)
{
	char			*str_element;
	void			*ptr_element;
	int				int_element;

	if (c == 'c')
		ft_putchar_fd(va_arg(ptr, int), 1);
	else if (c == 's')
	{
		str_element = va_arg(ptr, char *);
		ft_putstr_fd(str_element, 1);
		return (ft_strlen(str_element));
	}
	else if (c == 'p')
	{
		ptr_element = va_arg(ptr, void *);
		ft_putptr(ptr_element);
		return (2 + ft_ptr_len((uintptr_t)ptr_element));
	}
	else if (c == 'd' || c == 'i')
	{
		int_element = va_arg(ptr, int);
		ft_putnbr_fd(int_element, 1);
		return (ft_nb_len(int_element));
	}
	return (callfunction2(c, ptr));
}

int	ft_printf(const char *chaine, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	va_start(ptr, chaine);
	i = 0;
	count = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == '%' && chaine[i + 1] != '\0')
			count += callfunction(chaine[++i], ptr);
		else
		{
			ft_putchar_fd(chaine[i], 1);
			count++;
		}
		i++;
	}
	va_end(ptr);
	return (count);
}
