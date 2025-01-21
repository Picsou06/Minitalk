/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:01:51 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:01:56 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t				i;
	const unsigned char	*str;
	const unsigned char	*ptr;

	str = (const unsigned char *)pointer1;
	ptr = (const unsigned char *)pointer2;
	i = 0;
	while (i < size)
	{
		if (str[i] != ptr[i])
		{
			return (str[i] - ptr[i]);
		}
		i++;
	}
	return (0);
}
