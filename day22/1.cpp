#include <fstream>
#include <string>
#include <vector>
#include <ranges>

int main() {
    const char* format_incr = "deal with increment %d";
    const char* format_cut = "cut %d";

    auto cards = std::views::iota(0, 10007) | std::ranges::to<std::vector<int>>();

    std::string line; std::ifstream in("data.txt"); int cut{}, incr{};

    while (std::getline(in, line))
    {
        if (line == "deal into new stack") std::reverse(cards.begin(), cards.end());

        else if (sscanf(line.c_str(), format_cut, &cut) == 1) {
            if (cut > 0) std::rotate(cards.begin(), cards.begin() + cut, cards.end());
            else std::rotate(cards.rbegin(), cards.rbegin() + abs(cut), cards.rend());
        }

        else if (sscanf(line.c_str(), format_incr, &incr) == 1) {
            std::vector<int> temp(cards.size(), 0);

            for (int i{}; i < cards.size(); ++i) {
                temp[(i * incr) % cards.size()] = cards[i];
            }

            cards = std::move(temp);
        }
    }
    auto find = std::find(cards.begin(), cards.end(), 2019);

    printf("%d", std::distance(cards.begin(), find));
}