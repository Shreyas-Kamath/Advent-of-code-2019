#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

long long calc_ore(const auto& target, long long amount, const auto& reactions, auto& surplus) {
    if (target == "ORE") return amount;

    if (surplus[target] >= amount) { surplus[target] -= amount; return 0; }

    amount -= surplus[target];
    surplus[target] = 0;

    long long ore_needed = 0;

    const auto& [output_qty, inputs] = reactions.at(target);
    long long batches = (amount + output_qty - 1) / output_qty;

    for (const auto& [input, qty] : inputs) {
        ore_needed += calc_ore(input, qty * batches, reactions, surplus);
    }

    surplus[target] += (output_qty * batches) - amount;

    return ore_needed;
}

int main() {
    std::string line;
    std::ifstream in("data.txt");

    std::unordered_map<std::string, std::pair<int, std::vector<std::pair<std::string, int>>>> reactions;
    std::unordered_map<std::string, long long> surplus;

    while (std::getline(in, line)) {
        int quantity{};
        std::string token, rhs;
        std::vector<std::pair<std::string, int>> inputs;
        bool is_rhs = false;

        std::istringstream iss(line);
        while (iss >> token) {

            if (token == "=>") {
                is_rhs = true;
                continue;
            }

            if (std::isdigit(token[0])) {
                quantity = std::stoi(token);
                continue;
            }

            if (!is_rhs) {
                if (token.back() == ',') token.pop_back();
                inputs.emplace_back(token, quantity);
            } else rhs = token;
        
        }

        reactions[rhs] = {quantity, inputs};
    }

    std::cout << calc_ore("FUEL", 1, reactions, surplus);
}