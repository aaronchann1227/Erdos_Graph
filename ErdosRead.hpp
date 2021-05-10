#pragma once

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

/**
* Function to read from our data flie and convert it to erdosVec: the input of the constructor
*/
std::vector< std::vector<std::string> > readErdos();

/**
* Function to read from our data flie and create authorToPaper_: the input of the constructor
*/
std::unordered_map<std::string, unsigned int> createAuthorToPaper();