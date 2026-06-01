# 1223. Tree Depth From Encoding

## Problem Information

- Problem Number: 1223
- Difficulty: 🔴 Hard
- Topics: Trees, Recursion, Parsing

## Problem Statement

You are given a binary tree in a peculiar string representation. Each node is written in the form `(lr)`, where `l` corresponds to the left child and `r` corresponds to the right child.

If either `l` or `r` is null, it will be represented as a zero. Otherwise, it will be represented by a new `(lr)` pair.

Given this representation, determine the depth of the tree.

## Examples

### Example 1

- Input: `(00)`
- Output: `1`

### Example 2

- Input: `((00)(00))`
- Output: `2`

### Example 3

- Input: `((((00)0)0)0)`
- Output: `4`

## Solution Approach

Parse the string recursively. Every time the parser sees a node, it consumes the left subtree and the right subtree, then returns one plus the larger depth of the two children.

A zero represents a null child and contributes depth zero. Since the encoding is fully parenthesized, recursion naturally follows the structure of the tree.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "hard/1223-tree-depth-encoding/solution.cpp"

int main() {
    std::cout << treeDepth("((00)(00))") << '\n';
    return 0;
}
'@ | Set-Content .\run_1223.cpp
g++ -std=c++17 .\run_1223.cpp -o .\run_1223.exe
.\run_1223.exe
```

### Linux / macOS

```bash
cat > run_1223.cpp <<'EOF'
#include <iostream>
#include "hard/1223-tree-depth-encoding/solution.cpp"

int main() {
    std::cout << treeDepth("((00)(00))") << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1223.cpp -o run_1223
./run_1223
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(h)
