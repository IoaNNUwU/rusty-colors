#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 104857600

struct request {
    char *url;
};

struct response {
    char *data;
    size_t len;
};

struct mime_type {
    char *ext;
    char *type;
};

struct server_config {
    struct mime_type *mime_types;
    size_t num_mime_types;
};

struct client_info {
    int fd;
    struct sockaddr_in addr;
};

struct server_state {
    struct server_config config;
};

struct server_state *initialize_server();
void free_server_state(struct server_state *state);
void handle_client(struct client_info *client);
void *handle_client_thread(void *arg);

int main(int argc, char *argv[]) {
    struct server_state *state = initialize_server();
    int server_fd;
    struct sockaddr_in server_addr;

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // config socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to port
    if (bind(server_fd, 
            (struct sockaddr *)&server_addr, 
            sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    while (1) {
        // client info
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int *client_fd = malloc(sizeof(int));

        // accept client connection
        if ((*client_fd = accept(server_fd, 
                                (struct sockaddr *)&client_addr, 
                                &client_addr_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // create a new thread to handle client request
        struct client_info *client_info = malloc(sizeof(struct client_info));
        client_info->fd = *client_fd;
        client_info->addr = client_addr;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client_thread, (void *)client_info);
        pthread_detach(thread_id);
    }

    close(server_fd);
    free_server_state(state);
    return 0;
}

bool not_(bool b) {
    return !b;
}

