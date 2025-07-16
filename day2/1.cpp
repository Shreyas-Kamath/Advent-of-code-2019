#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> nums;

    std::ifstream in("data.txt"); std::string line{}, num{};

    std::getline(in, line);
    in.close();

    std::stringstream ss(line);

    while (std::getline(ss, num, ',')) nums.emplace_back(std::stoi(num));

    for (int i{}; i < nums.size(); i += 4) {
        if (nums[i] == 99) break;
        else if (nums[i] == 1) {
            nums[nums[i + 3]] = nums[nums[i + 2]] + nums[nums[i + 1]];
        }
        else if (nums[i] == 2) {
            nums[nums[i + 3]] = nums[nums[i + 2]] * nums[nums[i + 1]];
        }
        else break;
    }
    std::cout << nums[0];
    return 0;
}