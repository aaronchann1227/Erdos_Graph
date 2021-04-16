#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>

int main() {
    std::ifstream text("ErdosClean.csv");
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

    std::string authors = strStream.str();
    

    std::vector<std::string> out;
    std::stringstream ss(authors);
    while(ss.good()) {
      std::string substr;
      std::getline(ss, substr, ','); //get first string delimited by comma
      out.push_back(substr);
    }
    std::vector<std::string> result;
    for (unsigned int i = 0; i < out.size(); i+=2) {
        result.push_back(out[i] + " " + out[i+1]);
    }
    for (std::vector<std::string>::const_iterator i = result.begin(); i != result.end(); ++i)
        std::cout << *i << "\n";
    return 0;
}