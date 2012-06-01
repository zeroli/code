#include <string>
#include <iostream>
#include <fstream>

bool readin(const char* filename)
{
	// scan data file, and then fill result into GUI
	std::ifstream inf(filename);
	if (!inf.is_open()) {
		return false;
	}
	std::string line;
	while (getline(inf, line)) {
		int pos = -1;
		const char* key = "Date:";
		int keylen = strlen(key);
		if ((pos = (int)line.find(key)) != std::string::npos) {
			std::cout << key << " found: " << line.substr(pos+keylen).c_str() << std::endl;
			continue;			
		} 
		key = "Time:";
		keylen = strlen(key);
		if ((pos = (int)line.find(key)) != std::string::npos) {
			std::cout << key << " found: " << line.substr(pos+keylen).c_str() << std::endl;
			continue;
		} 
		key = "WORKSPACE:";
		keylen = strlen(key);
		if ((pos = (int)line.find(key)) != std::string::npos) {
			std::cout << key << " found: " << line.substr(pos+keylen).c_str() << std::endl;
			continue;
		} 
		key = "SENSOR LAYOUT:";
		keylen = strlen(key);
		if ((pos = (int)line.find(key)) != std::string::npos) {
			std::cout << key << " found: " << line.substr(pos+keylen).c_str() << std::endl;
			continue;
		}
		key = "USB Communication|";
		keylen = strlen(key);
		if ((pos = (int)line.find(key)) != std::string::npos) {
			std::cout << key << " found at col " << keylen << " " << line.substr(pos+keylen).c_str() << std::endl;
			inf.close();
			return true;			 
		}
	}
	inf.close();
	return true;
}

int main()
{
	const char* filename = "AUDDP2_20101201_221702_ANY_SIC.dat";
	readin(filename);
	return 0;
}
