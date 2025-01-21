/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:21:17 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:32:16 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;
	size_t	i;

	if (elementSize != 0 && elementCount > SIZE_MAX / elementSize)
		return (NULL);
	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < elementCount * elementSize)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
