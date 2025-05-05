#ifndef SERVER_H
#define SERVER_H

#include "queue.h"
#include <string>
#include <unordered_map>

using namespace std;

class Server
{
private:
    int port;
    int server_fd;

    // A map to store routes and file paths
    unordered_map<string, string> routes;

    // Queue to store requests
    Queue requestQueue;

    // Defining methods
    void setupSocket();
    void acceptConnections();
    string handleRequest(const string &path);
    string readFileContent(const string &filepath);

public:
    Server(int port);
    void addRoute(const string &path, const string &filepath);
    void start();
};

#endif
