/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:45:01 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:32:52 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_count_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		return (ft_count_hex(n / 16) + 1);
	else
		count++;
	return (count);
}

void	ft_puthex_lower(unsigned int n)
{
	if (n >= 16)
		ft_puthex_lower(n / 16);
	if (n % 16 < 10)
		ft_putchar_fd(ft_tolower(n % 16 + '0'), 1);
	else
		ft_putchar_fd(ft_tolower(n % 16 - 10 + 'a'), 1);
}

void	ft_puthex_toupper(unsigned int n)
{
	if (n >= 16)
		ft_puthex_toupper(n / 16);
	if (n % 16 < 10)
		ft_putchar_fd(ft_toupper(n % 16 + '0'), 1);
	else
		ft_putchar_fd(ft_toupper(n % 16 - 10 + 'a'), 1);
}

void	ft_puthex(unsigned long n)
{
	if (n >= 16)
		ft_puthex(n / 16);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', 1);
	else
		ft_putchar_fd(n % 16 - 10 + 'a', 1);
}
