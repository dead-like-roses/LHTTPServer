#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define DEF_PORT 8080

void mem_usage();

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Lenght: 12\n\nserwer dziala";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("LServer: Error occurred in socket. Exiting.");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(DEF_PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("LServer: Error occurred in bind. Exiting.");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0) {
        perror("LServer: Error occurred in listen. Exiting.");
        exit(EXIT_FAILURE);
    }
    while (1) {
        printf("LServer: Waiting for connection...\n");
        mem_usage();
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("LServer: Error occurred in accept. Exiting.");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        printf("Server: Sent message.\n");
        close(new_socket);
    }
}

void mem_usage(){
    struct rusage r_usage;

        int ret = getrusage(RUSAGE_SELF,&r_usage);
        if (ret == 0){
            printf("\rMemory usage: %ld kilobytes\n",r_usage.ru_maxrss);
        }
        else{
            printf("Error in getrusage. errno = %d\n", errno);
        }
}

