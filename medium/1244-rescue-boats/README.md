# 1244. Rescue Boats

## Problem Information

- Problem Number: 1244
- Difficulty: 🟡 Medium
- Topics: Arrays, Greedy, Two Pointers

## Problem Statement

If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is `k`, determine how many boats will be needed to save everyone.

## Examples

### Example 1

- Input: `weights = [100, 200, 150, 80]`, `k = 200`
- Output: `3`

## Solution Approach

Sort the weights. Use two pointers, one at the lightest person and one at the heaviest person.

If the lightest and heaviest people can share a boat, pair them and move both pointers. Otherwise, send the heaviest person alone. In either case, one boat is used per step, and the greedy choice is optimal.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "medium/1244-rescue-boats/solution.cpp"

int main() {
    const std::vector<int> weights = {100, 200, 150, 80};
    std::cout << boatsNeeded(weights, 200) << '\n';
    return 0;
}
'@ | Set-Content .\run_1244.cpp
g++ -std=c++17 .\run_1244.cpp -o .\run_1244.exe
.\run_1244.exe
```

### Linux / macOS

```bash
cat > run_1244.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "medium/1244-rescue-boats/solution.cpp"

int main() {
    const std::vector<int> weights = {100, 200, 150, 80};
    std::cout << boatsNeeded(weights, 200) << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1244.cpp -o run_1244
./run_1244
```

## Complexity Analysis

- Time Complexity: O(n log n)
- Space Complexity: O(1) extra space beyond sorting
