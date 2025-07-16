#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void run_intcode(std::vector<int>& nums, int input) {
    int i = 0;
    
    auto get_value = [&](int mode, int param) {
        return mode == 0 ? nums[param] : param;
    };

    while (i < nums.size()) {
        int instruction = nums[i];
        int opcode = instruction % 100;
        int first_param_mode = (instruction / 100) % 10;
        int second_param_mode = (instruction / 1000) % 10;
        int third_param_mode = (instruction / 10000) % 10;

        if (opcode == 99) break;

        if (opcode == 1 || opcode == 2) {
            int a = get_value(first_param_mode, nums[i + 1]);
            int b = get_value(second_param_mode, nums[i + 2]);
            int dest = nums[i + 3]; // Always position mode
            nums[dest] = (opcode == 1) ? (a + b) : (a * b);
            i += 4;
        } 
        else if (opcode == 3) {
            int dest = nums[i + 1];
            nums[dest] = input;
            i += 2;
        } 
        else if (opcode == 4) {
            int output = get_value(first_param_mode, nums[i + 1]);
            std::cout << output << std::endl;
            i += 2;
        }
        else if (opcode == 5) {
            int cond = get_value(first_param_mode, nums[i + 1]);
            if (cond != 0) 
                i = get_value(second_param_mode, nums[i + 2]);
            else 
                i += 3;
        }
        else if (opcode == 6) {
            int cond = get_value(first_param_mode, nums[i + 1]);
            if (cond == 0) 
                i = get_value(second_param_mode, nums[i + 2]);
            else 
                i += 3;
        }
        else if (opcode == 7) {
            int a = get_value(first_param_mode, nums[i + 1]);
            int b = get_value(second_param_mode, nums[i + 2]);
            int dest = nums[i + 3];
            nums[dest] = (a < b) ? 1 : 0;
            i += 4;
        }
        else if (opcode == 8) {
            int a = get_value(first_param_mode, nums[i + 1]);
            int b = get_value(second_param_mode, nums[i + 2]);
            int dest = nums[i + 3];
            nums[dest] = (a == b) ? 1 : 0;
            i += 4;
        }
        else {
            break;
        }
    }
}

int main() {
    std::vector<int> nums;
    std::ifstream in("data.txt");
    std::string line, num;

    std::getline(in, line);
    in.close();
    
    std::stringstream ss(line);
    while (std::getline(ss, num, ',')) 
        nums.emplace_back(std::stoi(num));

    run_intcode(nums, 5);
    return 0;
}
