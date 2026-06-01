# 1241. Find Celebrity

## Problem Information

- Problem Number: 1241
- Difficulty: 🟡 Medium
- Topics: Graphs, Greedy

## Problem Statement

At a party, there is a single person who everyone knows, but who does not know anyone in return. Given a list of `N` people and the `knows(a, b)` operation, find a way to identify the celebrity in `O(N)` time.

## Examples

### Example 1

- Input: A party of 4 people where person 2 is the celebrity
- Output: `2`

## Solution Approach

First, use a linear scan to find a candidate. If person `a` knows person `b`, then `a` cannot be the celebrity, so replace the candidate with `b`. Otherwise keep `a`.

After one pass, verify the candidate by checking that everyone knows them and that they know nobody else.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "medium/1241-find-celebrity/solution.cpp"

bool knows(int a, int b) {
    const bool matrix[4][4] = {
        {false, true, true, true},
        {false, false, true, true},
        {false, false, false, false},
        {false, true, true, true}
    };
    return matrix[a][b];
}

int main() {
    std::cout << findCelebrity(4, knows) << '\n';
    return 0;
}
'@ | Set-Content .\run_1241.cpp
g++ -std=c++17 .\run_1241.cpp -o .\run_1241.exe
.\run_1241.exe
```

### Linux / macOS

```bash
cat > run_1241.cpp <<'EOF'
#include <iostream>
#include "medium/1241-find-celebrity/solution.cpp"

bool knows(int a, int b) {
    const bool matrix[4][4] = {
        {false, true, true, true},
        {false, false, true, true},
        {false, false, false, false},
        {false, true, true, true}
    };
    return matrix[a][b];
}

int main() {
    std::cout << findCelebrity(4, knows) << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1241.cpp -o run_1241
./run_1241
```

## Complexity Analysis

- Time Complexity: O(N)
- Space Complexity: O(1)
