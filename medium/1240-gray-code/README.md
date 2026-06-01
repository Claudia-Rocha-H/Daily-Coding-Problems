# 1240. Gray Code

## Problem Information

- Problem Number: 1240
- Difficulty: 🟡 Medium
- Topics: Bit Manipulation, Recursion

## Problem Statement

Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around.

Given a number of bits `n`, generate a possible gray code for it.

## Examples

### Example 1

- Input: `n = 2`
- Output: `[00, 01, 11, 10]`

## Solution Approach

A standard construction is to build the sequence for `n - 1` bits, then mirror it with the new high bit set.

This preserves the one-bit difference between adjacent values, and also between the last and first value.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "medium/1240-gray-code/solution.cpp"

int main() {
    const std::vector<int> codes = grayCode(2);
    for (int code : codes) {
        std::cout << code << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1240.cpp
g++ -std=c++17 .\run_1240.cpp -o .\run_1240.exe
.\run_1240.exe
```

### Linux / macOS

```bash
cat > run_1240.cpp <<'EOF'
#include <iostream>
#include "medium/1240-gray-code/solution.cpp"

int main() {
    const std::vector<int> codes = grayCode(2);
    for (int code : codes) {
        std::cout << code << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1240.cpp -o run_1240
./run_1240
```

## Complexity Analysis

- Time Complexity: O(2^n)
- Space Complexity: O(2^n)
