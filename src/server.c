/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:44:51 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/30 22:27:14 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	static char c = 0;
	static int i = 0;

	if (signum == SIGUSR1)
		c |= (0 << i);
	else if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int main(void) {
    printf("Server PID: %d\n", getpid());
    while (1)
    {
        signal(SIGUSR2, sig_handler);
        signal(SIGUSR1, sig_handler);
        pause();
    }
    return 0;
}
