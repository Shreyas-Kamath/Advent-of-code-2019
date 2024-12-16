#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

int main() {
    std::ifstream in("data.txt");
    std::string line, num; std::vector<int> nums;
    std::getline(in, line);

    std::stringstream ss(line);
    while (std::getline(ss, num, ',')) nums.push_back(stoi(num));

    for (int i{}; i < nums.size(); i += 4){
        if (nums[i] == 99) break;
        else if (nums[i] == 1) nums[nums[i + 3]] = nums[nums[i + 2]] + nums[nums[i + 1]];
        else if (nums[i] == 2) nums[nums[i + 3]] = nums[nums[i + 2]] * nums[nums[i + 1]];
        else continue;
    }
    std::cout << nums.at(0);
    return 0;
}