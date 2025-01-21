/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:32:21 by tanton            #+#    #+#             */
/*   Updated: 2024/11/10 14:42:33 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_signe(const char *str, int *i)
{
	int	signe;

	signe = 1;
	if (str[*i] == '-')
	{
		if (signe == 1)
			signe = -1;
		else
			signe = 1;
	}
	if (str[*i] == '-' || str[*i] == '+')
		*i = *i + 1;
	return (signe);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = test_signe(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
