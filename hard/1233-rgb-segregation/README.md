# 1233. RGB Segregation

## Problem Information

- Problem Number: 1233
- Difficulty: 🔴 Hard
- Topics: Arrays, Two Pointers, Greedy

## Problem Statement

Given an array of strictly the characters `R`, `G`, and `B`, segregate the values of the array so that all the `R`s come first, the `G`s come second, and the `B`s come last.

You can only swap elements of the array.

## Examples

### Example 1

- Input: `['G', 'B', 'R', 'R', 'B', 'R', 'G']`
- Output: `['R', 'R', 'R', 'G', 'G', 'B', 'B']`
- Explanation: All `R` values are placed first, followed by `G`, then `B`.

## Solution Approach

Use three pointers to maintain four regions in the array:

- elements before `low` are `R`
- elements between `low` and `mid` are `G`
- elements between `mid` and `high` are unknown
- elements after `high` are `B`

Scan the array once. When the current value is `R`, swap it into the front region. When it is `G`, advance the middle pointer. When it is `B`, swap it into the back region and keep `mid` in place to inspect the swapped value next.

This is the Dutch National Flag pattern and satisfies the in-place linear-time requirement.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "hard/1233-rgb-segregation/solution.cpp"

int main() {
    std::vector<char> values = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    segregateRGB(values);
    for (char value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1233.cpp
g++ -std=c++17 .\run_1233.cpp -o .\run_1233.exe
.\run_1233.exe
```

### Linux / macOS

```bash
cat > run_1233.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "hard/1233-rgb-segregation/solution.cpp"

int main() {
    std::vector<char> values = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    segregateRGB(values);
    for (char value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1233.cpp -o run_1233
./run_1233
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

