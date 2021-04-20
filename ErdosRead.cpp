#include "readFromFile.hpp"
#include "readFromFile.cpp"
#include <string>
#include <iostream>
using namespace std;

void readErdos() {
    std::string result = file_to_string("Erdos_Clean.csv");
    std::cout << result << std::endl;
}