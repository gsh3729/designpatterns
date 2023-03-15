#include <iostream>
#include "logger.hpp"
using namespace std;

int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx; //why do we need to mention it here?

Logger :: Logger() 
{
    ctr++;
    cout << "New instance created. No of instances: " << ctr << endl;
}

void Logger :: log (string msg)
{
    cout << msg << endl;
}

Logger* Logger::getLogger() 
{
    if (loggerInstance == nullptr) //if logger is instantiated, no need to lock it. (double checking)
    {
        mtx.lock();
        if (loggerInstance == nullptr)
        {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}