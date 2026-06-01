#include <vector>

void segregateRGB(std::vector<char>& values) {
    std::size_t low = 0;
    std::size_t mid = 0;
    std::size_t high = values.size();

    if (high == 0) {
        return;
    }

    --high;

    while (mid <= high) {
        if (values[mid] == 'R') {
            char temp = values[low];
            values[low] = values[mid];
            values[mid] = temp;
            ++low;
            ++mid;
        } else if (values[mid] == 'G') {
            ++mid;
        } else {
            char temp = values[mid];
            values[mid] = values[high];
            values[high] = temp;
            if (high == 0) {
                break;
            }
            --high;
        }
    }
}
