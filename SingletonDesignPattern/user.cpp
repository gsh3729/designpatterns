#include <iostream>
#include "logger.hpp"
#include <thread>

using namespace std;

// int main()
// {
//     // Logger* logger1 = new Logger();
//     // logger1->log("this msg is from user 1");

//     // Logger* logger2 = new Logger();
//     // logger2->log("this msg is from user 2");

//     Logger* logger1 = Logger::getLogger();
//     logger1->log("this msg is from user 1");

//     Logger* logger2 = Logger::getLogger();
//     logger2->log("this msg is from user 2");
//     return 0;
// }

void user1logs()
{
    Logger* logger1 = Logger::getLogger();
    logger1->log("this msg is from user 1");
}

void user2logs()
{
    Logger* logger2 = Logger::getLogger();
    logger2->log("this msg is from user 2");
}

int main()
{
    thread t1(user1logs);
    thread t2(user2logs);

    t1.join();
    t2.join();
    return 0;
}