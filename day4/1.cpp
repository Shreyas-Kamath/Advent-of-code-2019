#include <string>
#include <iostream>

bool adjacent_digit(std::string& password){
    for (size_t i{}; i < password.length() - 1; ++i){
        if (password[i] == password[i + 1]) return true;
    }
    return false;
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
        if (adjacent_digit(password) && is_increasing(password)) count++;
    }
    std::cout << count;
    return 0;
}