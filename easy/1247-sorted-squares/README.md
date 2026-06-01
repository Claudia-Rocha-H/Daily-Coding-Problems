# 1247. Sorted Squares

## Problem Information

- Problem Number: 1247
- Difficulty: 🟢 Easy
- Topics: Arrays, Two Pointers

## Problem Statement

Given a sorted list of integers, square the elements and give the output in sorted order.

## Examples

### Example 1

- Input: `[-9, -2, 0, 2, 3]`
- Output: `[0, 4, 4, 9, 81]`

## Solution Approach

The input is already sorted, so the largest square must come from either end of the array.

Use two pointers, one at the start and one at the end. Compare the absolute values, place the larger square at the end of the result array, and move the corresponding pointer inward. Repeat until all values are placed.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "easy/1247-sorted-squares/solution.cpp"

int main() {
    const std::vector<int> values = {-9, -2, 0, 2, 3};
    const std::vector<int> squares = sortedSquares(values);

    for (int value : squares) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1247.cpp
g++ -std=c++17 .\run_1247.cpp -o .\run_1247.exe
.\run_1247.exe
```

### Linux / macOS

```bash
cat > run_1247.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "easy/1247-sorted-squares/solution.cpp"

int main() {
    const std::vector<int> values = {-9, -2, 0, 2, 3};
    const std::vector<int> squares = sortedSquares(values);

    for (int value : squares) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1247.cpp -o run_1247
./run_1247
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)
