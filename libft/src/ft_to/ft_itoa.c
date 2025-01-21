/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:31:27 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:02:18 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	calcsize(int n)
{
	int				size;
	unsigned int	num;

	size = 0;
	if (n <= 0)
	{
		size++;
		num = -n;
	}
	else
	{
		num = n;
	}
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	num;

	size = calcsize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	num = n;
	if (n < 0)
		num = -n;
	while (num != 0)
	{
		str[--size] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
