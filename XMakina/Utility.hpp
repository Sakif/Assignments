/* ECED 3403 - XM2 Assembler Project
Sakif Fahmid Zaman - B00756635

-- some utilites that are used in this project

 */
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Utility {

//split a line into tokens of words separated by delimeter char
std::vector<std::string> split(std::string, char);

std::string removeComment(std::string);

} // namespace Utility