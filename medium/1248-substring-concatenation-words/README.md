# 1248. Substring Concatenation of All Words

## Problem Information

- Problem Number: 1248
- Difficulty: 🟡 Medium
- Topics: Strings, Hash Table, Sliding Window

## Problem Statement

Given a string `s` and a list of words `words`, where each word is the same length, find all starting indices of substrings in `s` that are a concatenation of every word in `words` exactly once.

## Examples

### Example 1

- Input: `s = "dogcatcatcodecatdog"`, `words = ["cat", "dog"]`
- Output: `[0, 13]`
- Explanation: The substrings starting at indices `0` and `13` are valid concatenations.

### Example 2

- Input: `s = "barfoobazbitbyte"`, `words = ["dog", "cat"]`
- Output: `[]`
- Explanation: There is no substring composed of both `dog` and `cat`.

## Solution Approach

All words have the same length, so the search space can be scanned in fixed-size steps. For each possible alignment within the word length, maintain a sliding window over `s` and track the frequency of words currently inside the window.

When a word appears too many times, shrink the window from the left until the frequency constraint is valid again. Whenever the window contains exactly the required number of words, record its starting index.

This avoids checking every substring from scratch and keeps the solution efficient for large inputs.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "medium/1248-substring-concatenation-words/solution.cpp"

int main() {
    const std::vector<int> indices = findSubstringMatches("dogcatcatcodecatdog", {"cat", "dog"});
    for (int index : indices) {
        std::cout << index << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1248.cpp
g++ -std=c++17 .\run_1248.cpp -o .\run_1248.exe
.\run_1248.exe
```

### Linux / macOS

```bash
cat > run_1248.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "medium/1248-substring-concatenation-words/solution.cpp"

int main() {
    const std::vector<int> indices = findSubstringMatches("dogcatcatcodecatdog", {"cat", "dog"});
    for (int index : indices) {
        std::cout << index << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1248.cpp -o run_1248
./run_1248
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(k)

Where `n` is the length of `s` and `k` is the number of distinct words.

