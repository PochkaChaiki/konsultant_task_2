#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <vector>
#include <string>
#include <fstream>

void read_file(std::ifstream& file, std::vector<std::string>& text);

long count_pairs(std::vector<std::string>& text, const std::pair<std::string, std::string>& words, int max_distance);


#endif