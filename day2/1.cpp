#include <fstream>
#include <vector>
#include <string>
#include <ranges>

int main() {
    std::string line; std::ifstream in("data.txt");

    std::getline(in, line);

    auto nums = line
    | std::views::split(',')
    | std::views::transform([](auto&& subrange) { return std::stoi(std::string(subrange.begin(), subrange.end())); })
    | std::ranges::to<std::vector<int>>();

    for (int ip{}; ip < nums.size(); ip += 4) {
        int& instr = nums[ip];
        
        if (instr == 99) break;

        int& lhs_loc = nums[ip + 1];
        int& rhs_loc = nums[ip + 2];
        int& res_loc = nums[ip + 3]; 
        
        if (instr == 1) nums[res_loc] = nums[lhs_loc] + nums[rhs_loc];
        else if (instr == 2) nums[res_loc] = nums[lhs_loc] * nums[rhs_loc];
    }

    printf("%d", nums.front());
}