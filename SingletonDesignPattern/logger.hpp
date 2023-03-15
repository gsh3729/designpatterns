#ifndef logger_h 
#define logger_h 

#include <string>
#include <mutex>
using namespace std;

class Logger 
{
    static int ctr;
    static Logger* loggerInstance;
    static mutex mtx;
    Logger(); //private
    Logger(const logger&); //copy constructor private 
    Logger operator = (const Logger &); //operator overloading also private 
     
    public: 
        static Logger* getLogger();
        void log(string msg);
};

#endif