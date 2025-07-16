#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>

int main() {

    std::string line, start, end; std::ifstream in("data.txt");

    std::unordered_map<std::string, std::vector<std::string>> graph;

    while (std::getline(in, line)) {
        std::string parent, child;

        auto find = line.find(')');

        parent = line.substr(0, find);

        child = line.substr(find + 1);

        graph[parent].push_back(child);
        graph[child].push_back(parent);

        if (child == "YOU") start = parent;
        if (child == "SAN") end = parent;
         
    }

    std::unordered_set<std::string> visited;
    std::queue<std::pair<std::string, int>> q;

    q.push({ start, 0 });

    visited.insert(start);

    while (!q.empty()) {
        const auto [node, depth] = q.front();
        q.pop();

        if (node == end) {
            std::cout << depth;
            exit(0);
        }

        for (const auto& child: graph[node]) {
            if (!visited.contains(child)) {
                visited.insert(child);
                q.push({ child, depth + 1 });
            }
        }
    }

}