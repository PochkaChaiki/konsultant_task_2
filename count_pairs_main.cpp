#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include <utility>
#include <cctype>
#include <algorithm>
#include <deque>

long count_pairs(std::ifstream& file, std::pair<std::string, std::string> pair, int max_distance);

int main(int argc, char* argv[]){


    // system("chcp 1251");
    // std::string filename(argv[1]);
    // std::string word1 = argv[2], word2 = argv[3];
    // std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    // std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    // int max_distance = std::stoi(std::string(argv[4]));

    std::string filename = "text.txt";
    std::string word1 = "и", word2 = "тогда";
    int max_distance = 4;

    std::ifstream file (filename, std::ios::in);

    if (!file)
        return -1;
      
    long pairs = count_pairs(file, std::make_pair(word1, word2), max_distance);

    std::cout << pairs;

    return 0;
}

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); } // correct
                  );
    return s;
}

long count_pairs(std::ifstream& file, std::pair<std::string, std::string> pair, int max_distance){
    long count(0);
    std::string word;
    std::deque<int> amount;
    while(!file.eof()){
        file >> word;
        word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return std::ispunct(c) || std::isspace(c); }), word.end());
        word = str_tolower(word);
        // std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        // std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

        int n = 1;
        std::for_each(amount.begin(), amount.end(), [](int &dist) { ++dist; });
        if ((amount.size() != 0) && (amount[0] > max_distance+1))
            amount.pop_front();

        if (word == pair.first){
            amount.push_back(0);
            continue;
        }
        if ((word == pair.second) && (amount.size() != 0))
            ++count;
    }
    return count;
}