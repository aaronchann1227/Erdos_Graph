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
    std::ifstream text("Erdos.csv");
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

    std::string authors = strStream.str();

    std::vector<std::string> out;
    std::string delimiter = "&";

    size_t pos = 0;
    std::string token;
    while ((pos = authors.find(delimiter)) != std::string::npos) {
        token = authors.substr(0, pos);
        out.push_back(token);
        authors.erase(0, pos + delimiter.length());
    }

    
    unsigned con = 0;
    out[0].erase(0,1);
    //out[out.size() - 1].erase(out[out.size() - 1].length() - 2,out[out.size() - 1].length() - 1);
    for (std::vector<std::string>::const_iterator i = out.begin(); i != out.end(); ++i) {
        con++;
        std::cout << *i << "\n";
        if (con > 9) {break;}
    }
    size_t size = out.size();
    std::cout << size << "";
    std::cout << out[out.size() - 1];
    return 0;
}