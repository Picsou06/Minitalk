/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:43:47 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:02:16 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_trim_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	return (i);
}

static int	ft_trim_end(const char *s1, const char *set)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	len--;
	while (len >= 0 && ft_is_in_set(s1[len], set))
		len--;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
