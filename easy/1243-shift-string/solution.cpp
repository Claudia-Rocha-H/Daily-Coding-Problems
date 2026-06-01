#include <string>
#include <vector>

bool canShiftString(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }

    if (a.empty()) {
        return true;
    }

    const std::string text = a + a;
    const std::string& pattern = b;

    std::vector<int> prefix(pattern.size(), 0);
    for (std::size_t i = 1, j = 0; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = static_cast<std::size_t>(prefix[j - 1]);
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        prefix[i] = static_cast<int>(j);
    }

    for (std::size_t i = 0, j = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = static_cast<std::size_t>(prefix[j - 1]);
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == pattern.size()) {
            if (i + 1 - j < a.size()) {
                return true;
            }
            j = static_cast<std::size_t>(prefix[j - 1]);
        }
    }

    return false;
}
