#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
int main() {
    std::ifstream text("ErdosClean.csv");
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

    std::string authors = strStream.str();
    std::string s;

    std::vector<std::string> out;
    std::stringstream ss(authors);
    while (ss >> std::quoted(s)) {
        out.push_back(s);
    }

    
    
    for (std::vector<std::string>::const_iterator i = out.begin(); i != out.end(); ++i)
        std::cout << *i << " ";     
    return 0;
}