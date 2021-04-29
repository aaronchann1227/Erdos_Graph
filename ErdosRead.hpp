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



std::vector< std::vector<std::string> > readErdos();

std::unordered_map<std::string, unsigned int> createAuthorToPaper();