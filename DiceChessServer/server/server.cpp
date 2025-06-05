#include "server.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <iostream>
#include <cstring>

void run_server() {
    std::cout << "Dice Chess Server" << std::endl;
    std::cout << "###############################" << std::endl;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed\n";
        return;
    }

    sockaddr_in server_addr {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed\n";
        close(server_fd);
        return;
    }

    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listen failed\n";
        close(server_fd);
        return;
    }

    std::cout << "Server is listening on port 8080...\n" << std::endl;

    while (true) {
        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            std::cerr << "Accept failed\n";
            continue;
        }

        char buffer[1024] = {0};
        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            std::string message(buffer);
            std::cout << "Received: " << message << "\n";

            const char* success_msg = "Successfully received the message\n";
            send(client_fd, success_msg, strlen(success_msg), 0);
        }

        close(client_fd);
    }

    close(server_fd);
}
