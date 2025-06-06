//
// Created by zhaogan on 2025/6/6.
//

#ifndef ALGORITHM_LEETCODE543_H
#define ALGORITHM_LEETCODE543_H

#include "../util.h"

namespace LeetCode543 {
    class Solution {
    private:
        int maxNodes = 0;
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            countOfNodes(root);
            return maxNodes - 1;
        }

        int countOfNodes(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            int l = countOfNodes(root->left);
            int r = countOfNodes(root->right);
            maxNodes = max(maxNodes, l + r + 1);
            return max(l, r) + 1;
        }
    };
}

#endif //ALGORITHM_LEETCODE543_H
