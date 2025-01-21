/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:44:51 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/21 06:35:48 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	sig_handler(int signum)
{
    static int i = 0;
    static char c = 0;
    static int message_size = 0;
    static int size_received = 0;
    static char *message = NULL;

    if (size_received < 32)
    {
        if (signum == SIGUSR1)
            message_size = message_size | (0 << size_received);
        else if (signum == SIGUSR2)
            message_size = message_size | (1 << size_received);
        size_received++;
        if (size_received == 32)
        {
                message = malloc(message_size + 1);
                if (!message)
                {
                    ft_printf("Memory allocation failed\n");
                    exit(1);
                }
                message[message_size] = '\0';
            }
            else if (size_received > 32)
            {
                char *new_message = realloc(message, message_size + 1);
                if (!new_message)
                {
                    ft_printf("Memory reallocation failed\n");
                    free(message);
                    exit(1);
                }
                message = new_message;
                message[message_size] = '\0';
            if (!message)
            {
                ft_printf("Memory allocation failed\n");
                exit(1);
            }
            message[message_size] = '\0';
        }
    }
    else
    {
        if (i < message_size * 8)
        {
            if (i % 8 == 0)
                c = 0;
            if (signum == SIGUSR1)
                c = c | (0 << (i % 8));
            else if (signum == SIGUSR2)
                c = c | (1 << (i % 8));
            if (i % 8 == 7)
                message[i / 8] = c;
            i++;
        }
        if (i == message_size * 8)
        {
            ft_printf("Message received: %s\n", message);
            free(message);
            message = NULL;
            i = 0;
            c = 0;
            message_size = 0;
            size_received = 0;
        }
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
