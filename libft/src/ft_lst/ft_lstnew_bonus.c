/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:47:44 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:21:50 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_Llist	*ft_lstnew(void *content)
{
	t_Llist	*new;

	new = (t_Llist *)malloc(sizeof(t_Llist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
