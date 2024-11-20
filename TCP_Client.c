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
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    FILE *file;

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    // Reading bytes from a file and sending them to the server
    file = fopen("hw4input.txt", "r");
    if (file == NULL) {
        error("File open error");
    }

    // Check if the file is empty
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        fclose(file);
        error("No data in input file");
    }
    rewind(file);

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (send(sock, buffer, strlen(buffer), 0) < 0) {
            error("Send failed");
        }
        print_current_time();
        printf("Sent: %s", buffer);
        printf("\n");
        memset(buffer, 0, BUFFER_SIZE);
        sleep(10); // Delay of 10 seconds between sending each packet
    }

    fclose(file);
    close(sock);
    return 0;
}

