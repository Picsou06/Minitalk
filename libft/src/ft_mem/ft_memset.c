/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:46:23 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:02:00 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = pointer;
	val = (unsigned char) value;
	i = 0;
	while (i < count)
	{
		p[i++] = val;
	}
	return (pointer);
}
