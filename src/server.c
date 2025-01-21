#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void handle_signal(int signal) {
    if (signal == SIGUSR1) {
        ft_printf("Received SIGUSR1\n");
    } else if (signal == SIGUSR2) {
        ft_printf("Received SIGUSR2\n");
    }
}


int main(void) {
    printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1) {
        pause();
    }
    return 0;
}