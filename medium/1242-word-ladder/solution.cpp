#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::string> wordLadder(const std::string& start, const std::string& end, const std::vector<std::string>& dictionary) {
    std::unordered_set<std::string> words(dictionary.begin(), dictionary.end());
    if (words.find(end) == words.end()) {
        return {};
    }

    std::queue<std::string> frontier;
    frontier.push(start);
    std::unordered_map<std::string, std::string> parent;
    std::unordered_set<std::string> seen;
    seen.insert(start);

    while (!frontier.empty()) {
        const std::string current = frontier.front();
        frontier.pop();

        if (current == end) {
            break;
        }

        std::string next = current;
        for (std::size_t i = 0; i < next.size(); ++i) {
            const char original = next[i];
            for (char letter = 'a'; letter <= 'z'; ++letter) {
                if (letter == original) {
                    continue;
                }
                next[i] = letter;
                if (words.find(next) != words.end() && seen.find(next) == seen.end()) {
                    seen.insert(next);
                    parent[next] = current;
                    frontier.push(next);
                }
            }
            next[i] = original;
        }
    }

    if (seen.find(end) == seen.end()) {
        return {};
    }

    std::vector<std::string> path;
    for (std::string word = end;; word = parent[word]) {
        path.push_back(word);
        if (word == start) {
            break;
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}
