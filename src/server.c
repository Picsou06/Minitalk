/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 05:44:51 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/30 23:32:16 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <string.h>
#include <unistd.h>

void	send_received(int pid)
{
	kill(pid, SIGUSR2);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	void		context;

	if (signum == SIGUSR1)
		c |= (0 << i);
	else if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		printf("%c", c);
		if (c == '\0')
			send_received(info->si_pid);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
