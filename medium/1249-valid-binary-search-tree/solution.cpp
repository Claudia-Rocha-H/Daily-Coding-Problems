#include <limits>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

bool isWithinBounds(const TreeNode* node, long long minimumAllowed, long long maximumAllowed) {
    if (node == nullptr) {
        return true;
    }

    if (node->key < minimumAllowed || node->key > maximumAllowed) {
        return false;
    }

    return isWithinBounds(node->left, minimumAllowed, node->key) &&
           isWithinBounds(node->right, node->key, maximumAllowed);
}

bool isValidBST(const TreeNode* root) {
    return isWithinBounds(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}
