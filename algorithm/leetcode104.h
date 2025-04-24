//
// Created by Oliver on 2025/4/23.
//

#ifndef LEETCODE104_H
#define LEETCODE104_H

#include "../util.h"

namespace LeetCode104 {
    class Solution {
        int depth = 0;
        int res = 0;
    public:
        // 遍历实现
        int maxDepth(TreeNode* root) {
            traverse(root);
            return res;
        }

        void traverse(TreeNode* root) {
            if (root == nullptr) return;
            depth++;
            if (root->left == nullptr && root->right == nullptr) {
                res = max(res, depth);
            }
            traverse(root->left);
            traverse(root->right);
            depth--;
        }

        // 递归
        int maxDepth2(TreeNode* root) {
            if (root == nullptr) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
}

#endif //LEETCODE104_H
