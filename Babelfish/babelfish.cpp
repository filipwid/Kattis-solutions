#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> dictionary;
    std::string key, val;
    while (std::getline(std::cin, val) && !val.empty()) {
        size_t spot = val.find(' ');
        key = val.substr(spot + 1);
        dictionary[key] = val.substr(0, spot);
    }

    while (std::cin >> key) {
        if (dictionary.find(key) == dictionary.end()) {
            std::cout << "eh\n";
        }
        else {
            std::cout << dictionary[key] << "\n";
        }
    }

    return 0;
}