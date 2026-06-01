# 1252. Clock Angle

## Problem Information

- Problem Number: 1252
- Difficulty: 🟢 Easy
- Topics: Math, Strings

## Problem Statement

Given a clock time in `hh:mm` format, determine, to the nearest degree, the angle between the hour and the minute hands.

## Examples

### Example 1

- Input: `03:00`
- Output: `90`
- Explanation: The hands form a right angle.

### Example 2

- Input: `12:00`
- Output: `0`
- Explanation: Both hands overlap.

## Solution Approach

Convert the time into two angles measured from 12 o'clock.

- The minute hand moves `6` degrees per minute.
- The hour hand moves `30` degrees per hour plus `0.5` degrees per minute.

The raw angle is the absolute difference between both positions. Since the smaller angle is required, take the minimum between that difference and `360 - difference`, then round to the nearest degree.

### Bonus

The angle is zero when both hands overlap. In a 12-hour cycle, the overlap times satisfy `m = 60h / 11` for `h = 0..11`.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "easy/1252-clock-angle/solution.cpp"

int main() {
    std::cout << clockAngle("03:00") << '\n';
    std::cout << clockAngle("10:10") << '\n';
    return 0;
}
'@ | Set-Content .\run_1252.cpp
g++ -std=c++17 .\run_1252.cpp -o .\run_1252.exe
.\run_1252.exe
```

### Linux / macOS

```bash
cat > run_1252.cpp <<'EOF'
#include <iostream>
#include "easy/1252-clock-angle/solution.cpp"

int main() {
    std::cout << clockAngle("03:00") << '\n';
    std::cout << clockAngle("10:10") << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1252.cpp -o run_1252
./run_1252
```

## Complexity Analysis

- Time Complexity: O(1)
- Space Complexity: O(1)
