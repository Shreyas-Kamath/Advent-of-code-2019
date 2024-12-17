#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

size_t _count(std::string& _str, char _find){
    size_t count{};
    for (size_t i{}; i < _str.length(); ++i) if (_str[i] == _find) count++;
    return count;
}

int main() {
    std::ifstream in("data.txt");
    std::string layers;
    std::getline(in, layers);

    int width{25}; int height{6}; int layer_size{width * height};
    int min_zero_count{layer_size + 1};
    size_t ans{};

    for (int i{}; i < layers.length(); i += layer_size){
        std::string layer = layers.substr(i, layer_size);
        int zero_count = _count(layer, '0');

        if (zero_count < min_zero_count){
            min_zero_count = zero_count;
            ans = _count(layer, '1') * _count(layer, '2');
        }
    }
    std::cout << ans;
    return 0;
}