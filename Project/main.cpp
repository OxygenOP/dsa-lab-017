#include "server.h"
#include <iostream>

int main()
{
    Server server(8080);

    // Serve HTML files
    server.addRoute("/", "html/index.html");
    server.addRoute("/about", "html/about.html");
    server.addRoute("/contact", "html/contact.html");

    // Adding Tasks
    server.addRoute("/task1", "html/tasks/task1.html");
    server.addRoute("/task2", "html/tasks/task2.html");
    server.addRoute("/task3", "html/tasks/task3.html");
    server.addRoute("/task4", "html/tasks/task4.html");
    server.addRoute("/task5", "html/tasks/task5.html");
    server.addRoute("/task6", "html/tasks/task6.html");
    server.addRoute("/task7", "html/tasks/task7.html");
    server.addRoute("/task8", "html/tasks/task8.html");
    server.addRoute("/task9", "html/tasks/task9.html");
    server.addRoute("/task10", "html/tasks/task10.html");
    server.addRoute("/task11", "html/tasks/task11.html");

    server.start();

    return 0;
}
