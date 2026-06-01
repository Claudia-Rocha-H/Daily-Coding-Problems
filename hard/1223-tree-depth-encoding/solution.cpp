#include <algorithm>
#include <string>

int parseTreeDepth(const std::string& text, std::size_t& index) {
    if (index >= text.size()) {
        return 0;
    }

    if (text[index] == '0') {
        ++index;
        return 0;
    }

    if (text[index] != '(') {
        return 0;
    }

    ++index;
    const int leftDepth = parseTreeDepth(text, index);
    const int rightDepth = parseTreeDepth(text, index);

    if (index < text.size() && text[index] == ')') {
        ++index;
    }

    return 1 + std::max(leftDepth, rightDepth);
}

int treeDepth(const std::string& text) {
    std::size_t index = 0;
    return parseTreeDepth(text, index);
}
