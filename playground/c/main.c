#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#define PORT 8080

// Structure to represent a linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to insert a node at the end of the linked list
void insert_node(node **head, int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

// Function to print the linked list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[256];

    true;

    // Create a linked list
    node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    clilen = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (connfd < 0) {
        perror("accept failed");
        exit(1);
    }

    read(connfd, buffer, 256);
    printf("%s\n", buffer);

    char *response = "HTTP/1.1 200 OK\nContent-Length: 12\n\nHello, world!";
    send(connfd, response, strlen(response), 0);

    close(connfd);
    close(sockfd);
    return 0;
}

