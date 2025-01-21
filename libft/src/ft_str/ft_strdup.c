/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:41:43 by evdalmas          #+#    #+#             */
/*   Updated: 2024/11/09 15:46:05 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	sizesrc(char const *src)
{
	int	compteur;

	compteur = 0;
	while (*src)
	{
		src++;
		compteur++;
	}
	return (compteur);
}

char	*ft_strdup(char const *src)
{
	char	*copy;
	int		taille;
	int		i;

	taille = sizesrc(src);
	copy = (char *) malloc((taille + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
int	main(void)
{
	char	*src1 = "salutttttttttttttttttttttttttttttttttttttttttf";
	char	*copy = ft_strdup(src1);
	char	*copy2 = strdup(src1);
	printf("Moi: %s\n",copy);
	printf("Strdup: %s",copy2);
}*/
