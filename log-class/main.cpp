#include <iostream>

class Log
{
private:
    int m_LogLevel = LogLevelInfo;
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
    
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }
    
    void Info(const char* message){
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO] " << message << std::endl;  
    }

    void Warn(const char* message){
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING] " << message << std::endl;  
    }

    void Error(const char* message){
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR] " << message << std::endl;  
    }
};

int main(){
    Log log;
    log.SetLevel(log.LogLevelWarning);
    log.Warn("This is a friendly warning!");
    std::cin.get();
}