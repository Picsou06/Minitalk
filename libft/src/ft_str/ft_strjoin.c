/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:19:49 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:02:11 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	get_len(const char *str1, const char *str2)
{
	int	answer;
	int	i;

	answer = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		answer++;
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		answer++;
		i++;
	}
	return (answer);
}

char	*checkvalid(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && !s2)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	char	*valid_check;

	valid_check = checkvalid(s1, s2);
	if (valid_check)
		return (valid_check);
	result = malloc(sizeof(char) * (get_len(s1, s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i] = s2[j++];
		i++;
	}
	result[get_len(s1, s2)] = '\0';
	return (result);
}
