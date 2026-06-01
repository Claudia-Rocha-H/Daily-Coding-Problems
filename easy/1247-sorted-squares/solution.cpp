#include <cstdlib>
#include <vector>

std::vector<int> sortedSquares(const std::vector<int>& values) {
    std::vector<int> result(values.size());
    std::size_t left = 0;
    std::size_t right = values.size();

    while (left < right) {
        const std::size_t writeIndex = right - left - 1;
        const int leftValue = values[left];
        const int rightValue = values[right - 1];

        if (std::abs(leftValue) > std::abs(rightValue)) {
            result[writeIndex] = leftValue * leftValue;
            ++left;
        } else {
            result[writeIndex] = rightValue * rightValue;
            --right;
        }
    }

    return result;
}
