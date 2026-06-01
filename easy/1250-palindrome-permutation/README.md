# 1250. Palindrome Permutation

## Problem Information

- Problem Number: 1250
- Difficulty: 🟢 Easy
- Topics: Strings, Hash Table

## Problem Statement

Given a string, determine whether any permutation of it is a palindrome.

## Examples

### Example 1

- Input: `carrace`
- Output: `true`
- Explanation: It can be rearranged into `racecar`.

### Example 2

- Input: `daily`
- Output: `false`
- Explanation: No permutation forms a palindrome.

## Solution Approach

A string can be permuted into a palindrome if at most one character has an odd frequency.

Track the parity of each character as you scan the string. Toggling a character in an unordered set is enough: if the character is present, remove it; otherwise insert it. At the end, the set contains exactly the characters with odd counts.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "easy/1250-palindrome-permutation/solution.cpp"

int main() {
    std::cout << std::boolalpha;
    std::cout << canPermutePalindrome("carrace") << '\n';
    std::cout << canPermutePalindrome("daily") << '\n';
    return 0;
}
'@ | Set-Content .\run_1250.cpp
g++ -std=c++17 .\run_1250.cpp -o .\run_1250.exe
.\run_1250.exe
```

### Linux / macOS

```bash
cat > run_1250.cpp <<'EOF'
#include <iostream>
#include "easy/1250-palindrome-permutation/solution.cpp"

int main() {
    std::cout << std::boolalpha;
    std::cout << canPermutePalindrome("carrace") << '\n';
    std::cout << canPermutePalindrome("daily") << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1250.cpp -o run_1250
./run_1250
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(k)
