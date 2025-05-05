#include "server.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

Server::Server(int port) : port(port)
{
    setupSocket();
}

void Server::addRoute(const string &path, const string &filepath)
{
    routes[path] = filepath;
}

void Server::setupSocket()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    cout << "Server started on port " << port << endl;
}

void Server::start()
{
    acceptConnections();
}

void Server::acceptConnections()
{
    while (true)
    {
        sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);
        int client_socket = accept(server_fd, (struct sockaddr *)&client_address, &client_len);

        if (client_socket < 0)
        {
            perror("Accept failed");
            continue;
        }

        char buffer[1024] = {0};
        read(client_socket, buffer, 1024);

        string request(buffer);
        size_t pos1 = request.find("GET ");
        size_t pos2 = request.find(" HTTP/");
        string path = "/";
        if (pos1 != string::npos && pos2 != string::npos)
        {
            path = request.substr(pos1 + 4, pos2 - (pos1 + 4));
        }

        cout << "Received request for: " << path << endl;

        // Put path into queue
        requestQueue.enqueue(path);

        // Process the request
        string response;
        if (!requestQueue.isEmpty())
        {
            string reqPath = requestQueue.dequeue();
            response = handleRequest(reqPath);
        }

        // Send response
        string httpResponse = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + to_string(response.size()) + "\r\n\r\n" + response;

        send(client_socket, httpResponse.c_str(), httpResponse.size(), 0);

        close(client_socket);
    }
}

string Server::handleRequest(const string &path)
{
    if (routes.find(path) != routes.end())
    {
        return readFileContent(routes[path]);
    }
    return "<html><body><h1>404 Not Found</h1></body></html>";
}

string Server::readFileContent(const string &filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        return "<html><body><h1>500 Internal Server Error</h1></body></html>";
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}
