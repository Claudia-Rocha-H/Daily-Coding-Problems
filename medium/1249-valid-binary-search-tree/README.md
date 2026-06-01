# 1249. Valid Binary Search Tree

## Problem Information

- Problem Number: 1249
- Difficulty: 🟡 Medium
- Topics: Trees, Recursion

## Problem Statement

Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, `left` and `right`, and satisfies the constraint that the key in the `left` child must be less than or equal to the root and the key in the `right` child must be greater than or equal to the root.

## Examples

### Example 1

- Input: A valid BST with root `8`
- Output: `true`

### Example 2

- Input: A tree where a value in the left subtree is greater than the root
- Output: `false`

## Solution Approach

Validate the tree with a recursive range check.

Every node must stay within the allowed bounds inherited from its ancestors. For the left subtree, the upper bound becomes the current node value. For the right subtree, the lower bound becomes the current node value.

Because duplicates are allowed on both sides by the problem statement, the bounds are inclusive.

## Run the Solution

Use a temporary runner from the repository root.

### PowerShell

```powershell
@'
#include <iostream>
#include "medium/1249-valid-binary-search-tree/solution.cpp"

int main() {
    TreeNode leftLeft{1, nullptr, nullptr};
    TreeNode left{5, &leftLeft, nullptr};
    TreeNode right{9, nullptr, nullptr};
    TreeNode root{8, &left, &right};

    std::cout << std::boolalpha << isValidBST(&root) << '\n';
    return 0;
}
'@ | Set-Content .\run_1249.cpp
g++ -std=c++17 .\run_1249.cpp -o .\run_1249.exe
.\run_1249.exe
```

### Linux / macOS

```bash
cat > run_1249.cpp <<'EOF'
#include <iostream>
#include "medium/1249-valid-binary-search-tree/solution.cpp"

int main() {
    TreeNode leftLeft{1, nullptr, nullptr};
    TreeNode left{5, &leftLeft, nullptr};
    TreeNode right{9, nullptr, nullptr};
    TreeNode root{8, &left, &right};

    std::cout << std::boolalpha << isValidBST(&root) << '\n';
    return 0;
}
EOF
g++ -std=c++17 run_1249.cpp -o run_1249
./run_1249
```

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(h)
