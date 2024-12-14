#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("data.txt"); std::string line;
    int ans{};
    while (std::getline(in, line)) ans += stoi(line) / 3 - 2;

    std::cout << ans;
}