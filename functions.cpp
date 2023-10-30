#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

// void read_file(std::ifstream& file, std::vector<std::string>& text){
    
//     std::string word;
//     while (file >> word){
//         word.erase(std::remove_if(word.begin(), word.end(), [](char c){ return std::ispunct(c) || std::isspace(c); }), word.end());
//         if (!word.empty()) {
//             // Convert to lowercase and push back into vector
//             std::transform(word.begin(), word.end(), word.begin(), ::tolower);
//             text.push_back(word);
//         }
//     }
// }

// long count_pairs(std::vector<std::string>& text, const std::pair<std::string, std::string>& words, int max_distance){
//     long count;
//     for (int i(0); i < text.size() - 1; ++i){
//         if (text[i] == words.first){
//             for (int j(i + 1); (j < i + max_distance + 1) && (j < text.size()); ++j){
//                 if (text[j] == words.second) 
//                     ++count;
//             }
//         }
//     }
//     return count;
// }

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); } // correct
                  );
    return s;
}


int main(){
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::string a = "АБВГдеееееееееееЖ";
    std::cout << str_tolower(a) << "\n";
    system("pause");
    return 0;
}