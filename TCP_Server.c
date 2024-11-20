#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void print_current_time() {
    time_t now;
    time(&now);
    printf("Current time: %s", ctime(&now));
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    int valread;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Binding the socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        error("Listen failed");
    }

    printf("Server listening on port %d\n", PORT);

    // Accepting incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error("Accept failed");
    }

    // Reading data from the client
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[valread] = '\0'; // Null-terminate the received string
        print_current_time();
        printf("Received hex: %s", buffer);
        long long int num = strtoll(buffer, NULL, 16);
        printf("Converted to integer: %lld\n", num);
        printf("\n");
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (valread < 0) {
        error("Read failed");
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

