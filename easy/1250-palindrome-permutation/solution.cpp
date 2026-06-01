#include <string>
#include <unordered_set>

bool canPermutePalindrome(const std::string& text) {
    std::unordered_set<char> oddCharacters;

    for (char character : text) {
        if (oddCharacters.find(character) != oddCharacters.end()) {
            oddCharacters.erase(character);
        } else {
            oddCharacters.insert(character);
        }
    }

    return oddCharacters.size() <= 1;
}
