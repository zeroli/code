#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::string> SplitString( const char* instr, const char* splitChars )
{
	std::vector<std::string> out;

	int len = strcspn(instr, splitChars);
	while (instr[len])
	{
		out.push_back(std::string(instr, len));

		instr += len + 1;
		len = strcspn(instr, splitChars);
	}

	if (len > 0)
	{
		out.push_back(std::string(instr, len));
	}

	return out;
}

int main()
{
	std::string str = "A  B\tC   D";
	std::string delimiter = ",\t ";
	
	std::string::size_type pos1 = 0, pos2 = 0, duppos = 0;
	int ip = 0;
	while ((pos2 = str.find_first_of(delimiter, pos2)) != std::string::npos)
	{
		if (duppos != pos2) {
			std::cout << ip++ << ": " << str.substr(pos1, pos2-pos1) << std::endl;
		} 
		duppos = pos1 = ++pos2;
	}

	std::vector<std::string> splitV = SplitString(str.c_str(), delimiter.c_str());
	std::copy(splitV.begin(), splitV.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

	return 0;
}

