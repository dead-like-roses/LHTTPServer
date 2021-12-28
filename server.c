#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#define DEF_PORT 8080

char *notfound = NULL;

char *create_ok_response(char body[]) {
    char response_code_string[] = {"HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n"};
    char *str = (char *) malloc(strlen(response_code_string) + strlen(body));
    memcpy(str, response_code_string, strlen(response_code_string));
    memcpy(&str[strlen(response_code_string)], body, strlen(body));
    free(body);
    return str;
}

void create_static_folder() {
    struct stat st = {0};
    if (stat("./static", &st) == -1) {
        mkdir("./static", 0700);
    }
}

char *get_static_file(char name[]) {
    char path[] = "./static";
    char *proper_path = (char *) malloc(strlen(name) + strlen(path));
    memcpy(proper_path, path, strlen(path));
    memcpy(&proper_path[strlen(path)], name, strlen(name));
    if (access(proper_path, F_OK) == 0 && access(proper_path, R_OK) == 0) {
        FILE *fptr = fopen(proper_path, "r");
        if (fptr == NULL) {
            return notfound;
        }
        fseek(fptr, 0, SEEK_END);
        long fsize = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        char *content = (char *) malloc(fsize);
        fread(content, fsize, 1, fptr);
        fclose(fptr);
        free(proper_path);
        return create_ok_response(content);
    } else {
        return notfound;
    }
}

void setup_error_responses() {
    char temp[] = {"HTTP/1.1 404 NotFound\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n404 Not found"};
    notfound = (char *) malloc(strlen(temp));
    memcpy(notfound, temp, strlen(temp));
}

int main(int argc, char const *argv[]) {
    //setup 404
    setup_error_responses();
    //setup static folder
    create_static_folder();

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

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

        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("LServer: Error occurred in accept. Exiting.");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        int valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        if (valread < 0) {
            printf("No bytes are there to read");
        }
        char *res = get_static_file("/index.html"); //TODO change to path from request
        write(new_socket, res, strlen(res));
        free(res);
        printf("Server: Sent message.\n");
        close(new_socket);
    }
}
