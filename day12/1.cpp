#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct Position {
    int x{}, y{}, z{};
};

struct Velocity {
    int x{}, y{}, z{};
};

struct Moon {
    Position position;
    Velocity velocity;

    void applyGravity(const Moon& other) {
        if (position.x < other.position.x) velocity.x++;
        else if (position.x > other.position.x) velocity.x--;
        
        if (position.y < other.position.y) velocity.y++;
        else if (position.y > other.position.y) velocity.y--;
        
        if (position.z < other.position.z) velocity.z++;
        else if (position.z > other.position.z) velocity.z--;
    }

    void applyVelocity() {
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
    }
};

int main() {
    std::string line; std::ifstream in("data.txt");

    const char* format = "<x=%lld, y=%lld, z=%lld>";

    std::vector<Moon> moons;

    while (std::getline(in, line)) {
        Moon moon;
        if (std::sscanf(line.c_str(), format, &moon.position.x, &moon.position.y, &moon.position.z) == 3)
            moons.push_back(moon);
    }

    int totalEnergy = 0;

    for (int step{}; step < 1000; ++step) {
        for (int i{}; i < moons.size() - 1; ++i) {
            for (int j{i + 1}; j < moons.size(); ++j) {
                moons[i].applyGravity(moons[j]);
                moons[j].applyGravity(moons[i]);
            }
        }

        for (auto& moon: moons) moon.applyVelocity();
    }

    for (const auto& moon: moons) {
        int pe = std::abs(moon.position.x) + std::abs(moon.position.y) + std::abs(moon.position.z);
        int ke = std::abs(moon.velocity.x) + std::abs(moon.velocity.y) + std::abs(moon.velocity.z);
        totalEnergy += pe * ke;
    }

    std::cout << totalEnergy;
}