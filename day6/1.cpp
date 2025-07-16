#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int dfs(const auto& graph, const auto& node, int depth) {
    int total = depth;

    if (graph.contains(node)) {
        for (const auto& child: graph.at(node)) {
            total += dfs(graph, child, depth + 1);
        }
    }

    return total;
}

int main() {

    std::string line; std::ifstream in("data.txt");

    std::unordered_map<std::string, std::vector<std::string>> graph;

    while (std::getline(in, line)) {
        std::string parent, child;

        auto find = line.find(')');

        parent = line.substr(0, find);

        child = line.substr(find + 1);

        graph[parent].push_back(child);
    }


    std::string root = "COM";

    std::cout << dfs(graph, root, 0);

}