#include "SingletonExample.h"

class logger
{
public:
	logger() {}
	~logger() {}
	bool openLogFile(string);
	void writeToLogFile(string);
	bool closeLogFile(string);
private:
	
};

bool Logger::openLogFile(std::string)
{
	return true;
}

void Logger::writeToLogFile(std::string)
{

}

bool closeLogFile(std::string)
{
	return true;
}

typedef Singleton<logger> Logger;

int main()
{
	Logger::Instance()->openLogFile("logFile.txt");
	return 0;
}



