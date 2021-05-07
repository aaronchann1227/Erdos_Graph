
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
#include <unordered_map>

using namespace std;

std::vector<std::vector<std::string>> readErdos() {
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

  //out[0].erase(0,1);

  out.push_back("end123");

  std::vector< std::vector<std::string> > erdosVec;
  erdosVec.resize(513, std::vector<std::string> (0));

  unsigned count = 0;
  for (std::vector<std::string>::const_iterator i = out.begin(); i != out.end(); ++i) {
      while (*i != "end123") {
            erdosVec[count].push_back(*i);
            ++i;
            if ( i == out.end() ) {break;}
        }
        if (i == out.end() ) {break;}
        //std::cout << count << "\n";
        count++;
        if (count == 512) {
            //cout << "line 61";
            break;
        }
        //std::cout << "line 60" << "\n";
  }
  //getting a bug that the last line of file is not being parsed -- manual insert
  erdosVec[512] = vector<string> {"ZIV, ABRAHAM", "Aharoni, Merav", "Amdursky, Vardy", "Asaf, Sigal", "Fournier, Laurent", "Gal, Shmuel", "GINZBURG, ABRAHAM", "Maharik, Ron", "Nehama, Ilan", "Nikulshin, Ilya", "Rubinstein, Reuven Y."};

  return erdosVec;
}

std::unordered_map<std::string, unsigned int> createAuthorToPaper() {
  std::ifstream text("Publications.csv");
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

  std::string authors = strStream.str();

  std::vector<std::string> out;
  std::string delimiter = ":";

  size_t pos = 0;
  std::string token;

  while ((pos = authors.find(delimiter)) != std::string::npos) {
      token = authors.substr(0, pos);
      out.push_back(token);
      authors.erase(0, pos + delimiter.length());
  }

  std::unordered_map<std::string , unsigned int> authorToPaper;

  unsigned count = 0;
  for (size_t i = 0; i < out.size(); i += 2) {
      authorToPaper[out[i]] = std::stoi(out[i + 1]); 
      //std::cout << "createAuthorToPaper" << count;
      count++;
      if (count == 202) {
            //cout << "break at 202";
            break;
      }
  }
  return authorToPaper;
}