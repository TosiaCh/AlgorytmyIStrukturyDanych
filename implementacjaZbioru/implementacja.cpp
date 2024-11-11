#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

// odczyt i tokenizacja
std::vector<std::string> readAndTokenize(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string processedText;
    
    if (file.is_open()) {
        while (std::getline(file, line)) {
            for (char &ch : line) {
                if (std::isalpha(ch)) {
                    processedText += std::tolower(ch);
                } else if (!processedText.empty() && processedText.back() != ' ') {
                    processedText += ' ';
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }
    
    std::istringstream iss(processedText);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        if (token.size() > 2)
            tokens.push_back(token);
    }
    
    return tokens;
}

// sortowanie listy i usuwanie istniejących słów
void sortowanie(std::vector<std::string>& words){
    std::sort(words.begin(),words.end());
    std::vector<std::string> usuwanie;
    for(const auto& word : words){
        if(std::find(usuwanie.begin(),usuwanie.end(),word) == usuwanie.end()){
            usuwanie.push_back(word);
        }
    }
    words = usuwanie;
}

int main(int argc, char* argv[]) {

    std::string komenda = argv[1];
    std::string plik1 = argv[2];
    std::string plik2 = argv[3];

    std::vector<std::string> words1 = readAndTokenize(plik1);
    std::vector<std::string> words2 = readAndTokenize(plik2);

    sortowanie(words1);
    sortowanie(words2);

    if (komenda == "common_words") {
        std::vector<std::string> commonWords;
        for (const auto& word : words1) {
            if (std::binary_search(words2.begin(), words2.end(), word)) {
                commonWords.push_back(word);
            }
        }
        for (const auto& word : commonWords) {
            std::cout << word << std::endl;
        }
    } 
    else if (komenda == "unique_words") {
        std::vector<std::string> uniqueWords1;
        std::vector<std::string> uniqueWords2;
        
  for (const auto& word1 : words1) {
        if (std::find(words2.begin(), words2.end(), word1) == words2.end()) {
            uniqueWords1.push_back(word1);
        }
    }

    for (const auto& word2 : words2) {
        if (std::find(words1.begin(), words1.end(), word2) == words1.end()) {
            uniqueWords2.push_back(word2);
        }
    }
        std::cout << plik1 << ":" << std::endl;
        for (const auto& word : uniqueWords1) {
            std::cout << word << std::endl;
        }
        std::cout << plik2 << ":" << std::endl;
        for (const auto& word : uniqueWords2) {
            std::cout << word << std::endl;
        }
    } 
    else if (komenda == "all_words") {
        std::vector<std::string> allWords;
    
    for(const auto& word : words1) {
        allWords.push_back(word);
    }
        for(const auto& word : words2) {
        allWords.push_back(word);
    }
        sortowanie(allWords);

        for (const auto& word : allWords) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
