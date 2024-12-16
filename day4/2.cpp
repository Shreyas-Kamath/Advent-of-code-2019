#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

bool part_2(std::string& password){
    std::unordered_map<char, int> freq;
    for (const char& ch: password) freq[ch]++;
    return std::any_of(freq.begin(), freq.end(), [](const std::pair<char, int>& p) {return p.second == 2;});
}

bool is_increasing(std::string& password){
    for (size_t i{}; i < password.length() - 1; ++i){
        if ((password[i] - '0') > (password[i + 1] - '0')) return false;
    }
    return true;
}

int main() {

    int count{};
    for (int i{168630}; i < 718098; ++i){
        std::string password = std::to_string(i);
        if (part_2(password) && is_increasing(password)) count++;
    }
    std::cout << count;
    return 0;
}