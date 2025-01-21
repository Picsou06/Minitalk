#include "../libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main( int argc, char *argv[] ) {
    if (argc != 3) {
        ft_printf("Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    char *message = argv[2];
    for (int i = 0; message[i]; i++) {
        for (int j = 0; j < 8; j++) {
            if (message[i] & (1 << j)) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            usleep(100);
        }
    }
    return 0;
}