# 1243. Shift String

## Problem Information

- Problem Number: 1243
- Difficulty: 🟢 Easy
- Topics: Strings, Two Pointers

## Problem Statement

Given two strings A and B, return whether or not A can be shifted some number of times to get B.

A shift moves the first character of a string to the end of the string.

## Examples

### Example 1

- Input: A = `abcde`, B = `cdeab`
- Output: `true`
- Explanation: Shifting `abcde` two times produces `cdeab`.

### Example 2

- Input: A = `abc`, B = `acb`
- Output: `false`
- Explanation: No sequence of shifts turns `abc` into `acb`.

## Solution Approach

A string B is a rotation of A if and only if both strings have the same length and B appears as a substring of A + A.

To keep the solution efficient for larger inputs, the implementation uses KMP string matching to search for B inside A + A in linear time.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "easy/1243-shift-string/solution.cpp"

int main() {
	std::cout << std::boolalpha;
	std::cout << canShiftString("abcde", "cdeab") << '\n';
	std::cout << canShiftString("abc", "acb") << '\n';
	return 0;
}
'@ | Set-Content .\run_1243.cpp
g++ -std=c++17 .\run_1243.cpp -o .\run_1243.exe
.\run_1243.exe
```

### Linux / macOS

```bash
cat > run_1243.cpp <<'EOF'
#include <iostream>
#include "easy/1243-shift-string/solution.cpp"

int main() {
	std::cout << std::boolalpha;
	std::cout << canShiftString("abcde", "cdeab") << '\n';
	std::cout << canShiftString("abc", "acb") << '\n';
	return 0;
}
EOF
g++ -std=c++17 run_1243.cpp -o run_1243
./run_1243
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(n)
