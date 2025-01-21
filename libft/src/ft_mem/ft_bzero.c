/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:49:16 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:05:44 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_bzero(void *pointer, size_t count)
{
	unsigned char	*p;
	unsigned long	i;

	p = pointer;
	i = 0;
	while (i < count)
		p[i++] = 0;
	return (pointer);
}
