#include <string>
#include <vector>

std::vector<std::string> justifyText(const std::vector<std::string>& words, int width) {
    std::vector<std::string> lines;
    std::size_t index = 0;

    while (index < words.size()) {
        std::size_t lineStart = index;
        int letters = 0;

        while (index < words.size()) {
            const int nextLength = letters + static_cast<int>(words[index].size()) + static_cast<int>(index - lineStart);
            if (nextLength > width) {
                break;
            }
            letters += static_cast<int>(words[index].size());
            ++index;
        }

        const std::size_t lineEnd = index;
        const std::size_t wordCount = lineEnd - lineStart;
        const bool isLastLine = lineEnd == words.size();

        std::string line;
        if (wordCount == 1 || isLastLine) {
            for (std::size_t i = lineStart; i < lineEnd; ++i) {
                if (!line.empty()) {
                    line.push_back(' ');
                }
                line += words[i];
            }
            line.append(static_cast<std::size_t>(width - static_cast<int>(line.size())), ' ');
        } else {
            const int spacesNeeded = width - letters;
            const int gapCount = static_cast<int>(wordCount - 1);
            const int evenSpaces = spacesNeeded / gapCount;
            const int extraSpaces = spacesNeeded % gapCount;

            for (std::size_t i = lineStart; i < lineEnd; ++i) {
                line += words[i];
                if (i + 1 < lineEnd) {
                    const int spacesHere = evenSpaces + (static_cast<int>(i - lineStart) < extraSpaces ? 1 : 0);
                    line.append(static_cast<std::size_t>(spacesHere), ' ');
                }
            }
        }

        lines.push_back(line);
    }

    return lines;
}
