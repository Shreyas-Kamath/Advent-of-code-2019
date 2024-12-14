#include <fstream>
#include <iostream>
#include <string>

int calc_fuel(int fuel){
    int ans = 0;
    while (fuel > 0){
        fuel = fuel / 3 - 2;
        if (fuel > 0) ans += fuel;
    }
    return ans;
}

int main() {
    std::ifstream in("data.txt"); std::string line;
    int ans{};
    while (std::getline(in, line)){ 
        int init = stoi(line);
        ans += calc_fuel(init);
        }
    in.close();
    std::cout << ans;
}