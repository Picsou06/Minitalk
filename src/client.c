/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:44:48 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/21 06:47:27 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int send_message_size(int pid, int size)
{
    int i;
    int bit;

    i = 0;
    while (i < 32)
    {
        bit = (size >> i) & 1;
        if (bit == 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        i++;
        usleep(100);
    }
    return 0;
}

int send_message(int pid, char* message)
{
    int i;
    int j;
    int bit;
    char c;

    i = 0;
    while (message[i])
    {
        c = message[i];
        j = 0;
        while (j < 8)
        {
            bit = (c >> j) & 1;
            if (bit == 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            j++;
            usleep(100);
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        ft_printf("Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    char *message = argv[2];
    send_message_size(pid, ft_strlen(message));
    send_message(pid, message);
    return 0;
}