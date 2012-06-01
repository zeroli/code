#include <iostream>
#include <string>

int main()
{
	bool testb;
	std::cout << "boolean default value: ";
	if (testb) {
		std::cout << "true !\n";
	} else {
		std::cout << "false !\n";
	}

	std::string astr("I am a");
	std::string bstr("am a");
	if (astr.compare(bstr) < 0) {
		std::cout << "\"" << astr << "\" does not start with \"" << bstr << "\"\n";
	} else {
		std::cout << "\"" << astr << "\" does start with \"" << bstr << "\"\n";
	}
	return 0;
}

