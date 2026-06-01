# 1245. Text Justification

## Problem Information

- Problem Number: 1245
- Difficulty: 🟡 Medium
- Topics: Strings, Greedy

## Problem Statement

Write an algorithm to justify text. Given a sequence of words and an integer line length `k`, return a list of strings which represents each line, fully justified.

Each line should contain as many words as possible, with at least one space between words. Extra spaces must be distributed as evenly as possible, starting from the left. If a line contains only one word, pad the right-hand side with spaces.

## Examples

### Example 1

- Input: `words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]`, `k = 16`
- Output: `[
  "the  quick brown",
  "fox  jumps  over",
  "the   lazy   dog"
]`

## Solution Approach

Scan the words from left to right and group as many as possible into the current line without exceeding the target width.

For each line:
- If it is the last line, or it contains only one word, left-justify it and pad the right side.
- Otherwise, distribute the remaining spaces across the gaps.
- Give one extra space to the leftmost gaps when the division is uneven.

This greedy pass is sufficient because every line can be decided independently once the next word would exceed the width.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "medium/1245-text-justification/solution.cpp"

int main() {
    const std::vector<std::string> words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    const std::vector<std::string> lines = justifyText(words, 16);

    for (const std::string& line : lines) {
        std::cout << '|' << line << "|\n";
    }

    return 0;
}
'@ | Set-Content .\run_1245.cpp
g++ -std=c++17 .\run_1245.cpp -o .\run_1245.exe
.\run_1245.exe
```

### Linux / macOS

```bash
cat > run_1245.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "medium/1245-text-justification/solution.cpp"

int main() {
    const std::vector<std::string> words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    const std::vector<std::string> lines = justifyText(words, 16);

    for (const std::string& line : lines) {
        std::cout << '|' << line << "|\n";
    }

    return 0;
}
EOF
g++ -std=c++17 run_1245.cpp -o run_1245
./run_1245
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)
