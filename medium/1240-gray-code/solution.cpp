#include <vector>

std::vector<int> grayCode(int bits) {
    std::vector<int> codes = {0};

    for (int bit = 0; bit < bits; ++bit) {
        const int highBit = 1 << bit;
        for (int index = static_cast<int>(codes.size()) - 1; index >= 0; --index) {
            codes.push_back(codes[index] | highBit);
        }
    }

    return codes;
}
