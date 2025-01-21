/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:04:03 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:24:32 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	is_match(char *str, char *to_find)
{
	while (*to_find && *str && *to_find == *str)
	{
		to_find++;
		str++;
	}
	return (*to_find == '\0');
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char		*answer;
	size_t			i;
	size_t			size;

	if (*needle == '\0')
		return ((char *)haystack);
	size = 0;
	while (needle[size] != '\0')
		size++;
	i = 0;
	while (*haystack && i < len)
	{
		if (*haystack == *needle)
		{
			answer = haystack;
			if (is_match((char *)haystack, (char *)needle) \
				&& i + size - 1 < len)
			{
				return ((char *)answer);
			}
		}
		i++;
		haystack++;
	}
	return (NULL);
}
