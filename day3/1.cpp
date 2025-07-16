#include <unordered_set>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

struct Point {
    int x{}, y{};

    bool operator ==(const Point& other) const {
        return this->x == other.x && this->y == other.y;
    }
};


namespace std {
    template <>
    struct hash<Point> {
        std::size_t operator ()(const Point& p) const noexcept {
            return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
        }
    };
}

int main() {
    std::string line1, line2; std::ifstream in("data.txt");
    std::unordered_set<Point> visited; visited.reserve(10000);

    std::getline(in, line1); std::istringstream iss1(line1);
    std::getline(in, line2); std::istringstream iss2(line2);

    std::string token; int x{}, y{};

    while (std::getline(iss1, token, ',')) {
        auto& direction = token.front();

        int steps = std::stoi(token.substr(1));

        for (int i{}; i < steps; ++i) {
            switch (direction) {
                case 'U': { ++y; visited.emplace(x, y); break; }
                case 'D': { --y; visited.emplace(x, y); break; }
                case 'L': { --x; visited.emplace(x, y); break; }
                case 'R': { ++x; visited.emplace(x, y); break; }
            }
        }
    }

    x = y = 0;

    int min_dist = INT_MAX;

    while (std::getline(iss2, token, ',')) {
        auto& direction = token.front();

        int steps = std::stoi(token.substr(1));

        for (int i{}; i < steps; ++i) {
            switch (direction) {
                case 'U': { ++y; break; }
                case 'D': { --y; break; }
                case 'L': { --x; break; }
                case 'R': { ++x; break; }
            }

            if (visited.contains({ x, y })) min_dist = std::min(min_dist, std::abs(x) + std::abs(y));
        }
    }

    std::cout << min_dist;
}