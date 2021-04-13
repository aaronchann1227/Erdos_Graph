#include "readFromFile.hpp"
#include "readFromFile.cpp"
#include <string>
#include <iostream>
using namespace std;

void readErdos() {
    std::string result = file_to_string("ErdosClean.csv");
    std::cout << result << std::endl;
}