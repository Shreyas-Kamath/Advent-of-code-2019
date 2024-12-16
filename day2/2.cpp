#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

bool help(std::vector<int> nums, int noun, int verb){
    nums[1] = noun; nums[2] = verb;
    for (int i{}; i < nums.size(); i += 4){
        if (nums[i] == 99) break;
        else if (nums[i] == 1) nums[nums[i + 3]] = nums[nums[i + 2]] + nums[nums[i + 1]];
        else if (nums[i] == 2) nums[nums[i + 3]] = nums[nums[i + 2]] * nums[nums[i + 1]];
        else continue;
    }
    return nums[0] == 19690720;
}

int main() {
    std::ifstream in("data.txt");
    std::string line, num; std::vector<int> nums;
    std::getline(in, line);

    std::stringstream ss(line);
    while (std::getline(ss, num, ',')) nums.push_back(stoi(num));

    for (int noun{}; noun < 100; ++noun){
        for (int verb{}; verb < 100; ++verb){
            if (help(nums, noun, verb)) std::cout << 100 * noun + verb;
        }
    }
    
    return 0;
}