#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "ExponentialSeries.h"

#define PORT 8081

// HTTP headers
const char HTTP_200_HEADER[] = "HTTP/1.1 200 OK\r\n";
const char HTTP_404_HEADER[] = "HTTP/1.1 404 Not Found\r\n";

// Function to create and run the HTTP server
void CreateHTTPserver() {
    int connectionSocket, clientSocket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket
    if ((connectionSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configuring server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the port
    if (bind(connectionSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        close(connectionSocket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(connectionSocket, 10) < 0) {
        perror("Listening failed");
        close(connectionSocket);
        exit(EXIT_FAILURE);
    }

    printf("\n------ Server is running on port %d ------\n", PORT);

    while (true) {
        printf("\n------ Waiting for a new connection ------\n");

        // Accepting a new connection
        if ((clientSocket = accept(connectionSocket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[30000] = {0};
        read(clientSocket, buffer, sizeof(buffer));
        printf("Request received:\n%s\n", buffer);

        // Handle `/compute` endpoint
        if (strstr(buffer, "/compute")) {
            auto start = std::chrono::high_resolution_clock::now();

            // Generate and process data
            std::vector<double> results;
            ExponentialSeries expSeries;
            int n = 150000000;// Adjust n to make the computation last ~15 seconds
            for (int i = 0; i < n; ++i) {
                results.push_back(expSeries.FuncA(i % 10));
            }
            std::sort(results.begin(), results.end());

            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            // Send response
            std::string body = "Processing took " + std::to_string(elapsed) + " ms\n";
            std::string response = std::string(HTTP_200_HEADER) +
                                   "Content-Type: text/plain\r\n" +
                                   "Content-Length: " + std::to_string(body.size()) + "\r\n\r\n" + body;

            write(clientSocket, response.c_str(), response.size());
            printf("\nResponse sent: Time elapsed = %ld ms\n", elapsed);
        } else {
            // Handling unknown route
            std::string notFoundResponse = std::string(HTTP_404_HEADER) + "Content-Type: text/plain\r\nContent-Length: 13\r\n\r\n404 Not Found";
            write(clientSocket, notFoundResponse.c_str(), notFoundResponse.size());
        }

        // Close the connection
        close(clientSocket);
    }

    close(connectionSocket);
}
