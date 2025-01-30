/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:44:48 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/30 23:31:15 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	send_end(int pid)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(800);
	}
	return (0);
}

int	send_message(int pid, char *message)
{
	int		i;
	int		j;
	int		bit;
	char	c;

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
			usleep(800);
		}
		i++;
	}
	send_end(pid);
	return (0);
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Message recu\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*temp;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	temp = ft_strjoin(argv[2], "\n");
	signal(SIGUSR2, handle_signal);
	send_message(pid, temp);
	free(temp);
	while (1)
	{
		pause();
	}
	return (0);
}
