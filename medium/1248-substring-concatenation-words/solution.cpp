#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubstringMatches(const std::string& s, const std::vector<std::string>& words) {
    std::vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }

    const std::size_t wordLength = words.front().size();
    const std::size_t totalWords = words.size();
    const std::size_t windowLength = wordLength * totalWords;

    if (wordLength == 0 || s.size() < windowLength) {
        return result;
    }

    std::unordered_map<std::string, int> required;
    for (const std::string& word : words) {
        ++required[word];
    }

    for (std::size_t offset = 0; offset < wordLength; ++offset) {
        std::unordered_map<std::string, int> seen;
        std::size_t left = offset;
        std::size_t matchedWords = 0;

        for (std::size_t right = offset; right + wordLength <= s.size(); right += wordLength) {
            const std::string currentWord = s.substr(right, wordLength);
            auto requiredIt = required.find(currentWord);

            if (requiredIt == required.end()) {
                seen.clear();
                matchedWords = 0;
                left = right + wordLength;
                continue;
            }

            ++seen[currentWord];
            ++matchedWords;

            while (seen[currentWord] > requiredIt->second) {
                const std::string leftWord = s.substr(left, wordLength);
                --seen[leftWord];
                --matchedWords;
                left += wordLength;
            }

            if (matchedWords == totalWords) {
                result.push_back(static_cast<int>(left));
                const std::string leftWord = s.substr(left, wordLength);
                --seen[leftWord];
                --matchedWords;
                left += wordLength;
            }
        }
    }

    return result;
}
