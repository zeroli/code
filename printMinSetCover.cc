#include <iostream>
#include <fstream>
#include <set>

void printAllElements(const std::set<int>& s)
{
	std::cout << "All elements: ( " << s.size() << " )" << std::endl;
	std::set<int>::const_iterator it = s.begin();
	for (; it!=s.end(); ++it) 
		std::cout << *it << " ";
	std::cout << "\n" << "============================\n"
		<< "totally elements ( " << s.size() << " )\n";
}

int main()
{
	const char* filename = "minSetCover0.txt";
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "Error to load file: " << filename << std::endl;
		exit(-1);
	}
	int ele = -1;
	std::set<int> s;
	while (inFile >> ele) 
		s.insert(ele);
	
	inFile.close();
	
	printAllElements(s);
	return 0;
}
	
