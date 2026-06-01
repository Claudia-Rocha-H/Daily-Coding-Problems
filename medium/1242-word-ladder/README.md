# 1242. Word Ladder

## Problem Information

- Problem Number: 1242
- Difficulty: 🟡 Medium
- Topics: Graphs, BFS

## Problem Statement

Given a `start` word, an `end` word, and a dictionary of valid words, find the shortest transformation sequence from `start` to `end` such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no possible transformation, return null.

## Examples

### Example 1

- Input: `start = "dog"`, `end = "cat"`, `dictionary = {"dot", "dop", "dat", "cat"}`
- Output: `["dog", "dot", "dat", "cat"]`

### Example 2

- Input: `start = "dog"`, `end = "cat"`, `dictionary = {"dot", "tod", "dat", "dar"}`
- Output: `null`

## Solution Approach

Use breadth-first search, because every transformation has the same cost.

From each word, generate all possible one-letter variations and keep only those found in the dictionary. Store each word's parent so the path can be rebuilt once the end word is reached.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "medium/1242-word-ladder/solution.cpp"

int main() {
    const std::vector<std::string> dictionary = {"dot", "dop", "dat", "cat"};
    const std::vector<std::string> path = wordLadder("dog", "cat", dictionary);

    for (const std::string& word : path) {
        std::cout << word << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1242.cpp
g++ -std=c++17 .\run_1242.cpp -o .\run_1242.exe
.\run_1242.exe
```

### Linux / macOS

```bash
cat > run_1242.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "medium/1242-word-ladder/solution.cpp"

int main() {
    const std::vector<std::string> dictionary = {"dot", "dop", "dat", "cat"};
    const std::vector<std::string> path = wordLadder("dog", "cat", dictionary);

    for (const std::string& word : path) {
        std::cout << word << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1242.cpp -o run_1242
./run_1242
```

## Complexity Analysis

- Time Complexity: O(26 * L * N)
- Space Complexity: O(N)
