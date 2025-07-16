#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

bool test(std::vector<int> nums, int noun, int verb) {
    nums[1] = noun; nums[2] = verb;
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
    return nums[0] == 19690720;
} 


int main() {
    std::vector<int> nums;

    std::ifstream in("data.txt"); std::string line{}, num{};

    std::getline(in, line);
    in.close();

    std::stringstream ss(line);

    while (std::getline(ss, num, ',')) nums.emplace_back(std::stoi(num)); bool found{false};

    for (int noun{}; noun <= 99; ++noun) {
        for (int verb{}; verb <= 99; ++verb) {
            if (test(nums, noun, verb)) { found = true; std::cout << 100 * noun + verb; break; }
        }
        if (found) break;
    }

    return 0;
}