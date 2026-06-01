#include <algorithm>
#include <vector>

int boatsNeeded(std::vector<int> weights, int limit) {
    std::sort(weights.begin(), weights.end());

    std::size_t left = 0;
    std::size_t right = weights.size();
    int boats = 0;

    while (left < right) {
        --right;
        if (weights[left] + weights[right] <= limit) {
            ++left;
        }
        ++boats;
    }

    return boats;
}
