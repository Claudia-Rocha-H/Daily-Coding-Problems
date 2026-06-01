# 1254. Minimum Stabbing Points

## Problem Information

- Problem Number: 1254
- Difficulty: 🔴 Hard
- Topics: Greedy, Sorting, Intervals

## Problem Statement

Let `X` be a set of `n` intervals on the real line. We say that a set of points `P` stabs `X` if every interval in `X` contains at least one point in `P`.

Compute the smallest set of points that stabs the intervals.

## Examples

### Example 1

- Input: `[(1, 4), (4, 5), (7, 9), (9, 12)]`
- Output: `[4, 9]`
- Explanation: Points `4` and `9` hit every interval.

## Solution Approach

Sort the intervals by their ending point.

Then scan them from left to right, always choosing the end of the first uncovered interval as the next stabbing point. This is optimal because picking the earliest possible end leaves the most room to cover future intervals.

Whenever the next interval starts after the current stabbing point, add its end to the answer and continue.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include <vector>
#include "hard/1254-minimum-stabbing-points/solution.cpp"

int main() {
    std::vector<Interval> intervals = {
        {1, 4},
        {4, 5},
        {7, 9},
        {9, 12}
    };

    const std::vector<double> points = chooseStabbingPoints(intervals);
    for (double point : points) {
        std::cout << point << ' ';
    }
    std::cout << '\n';
    return 0;
}
'@ | Set-Content .\run_1254.cpp
g++ -std=c++17 .\run_1254.cpp -o .\run_1254.exe
.\run_1254.exe
```

### Linux / macOS

```bash
cat > run_1254.cpp <<'EOF'
#include <iostream>
#include <vector>
#include "hard/1254-minimum-stabbing-points/solution.cpp"

int main() {
    std::vector<Interval> intervals = {
        {1, 4},
        {4, 5},
        {7, 9},
        {9, 12}
    };

    const std::vector<double> points = chooseStabbingPoints(intervals);
    for (double point : points) {
        std::cout << point << ' ';
    }
    std::cout << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1254.cpp -o run_1254
./run_1254
```

## Complexity Analysis

- Time Complexity: O(n log n)
- Space Complexity: O(1) extra space beyond the output
