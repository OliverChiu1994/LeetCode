//
// Created by zhaogan on 2025/6/6.
//

#ifndef LEETCODE_LEETCODE101_H
#define LEETCODE_LEETCODE101_H

#include "../util.h"

namespace LeetCode101 {
    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            return isSymmetric(root->left, root->right);
        }

        bool isSymmetric(TreeNode* root1, TreeNode* root2) {
            if (root1 == nullptr) {
                return root2 == nullptr;
            }
            if (root2 == nullptr) return false;
            bool valBool = root1->val == root2->val;
            return  valBool &&
                isSymmetric(root1->left, root2->right) &&
                isSymmetric(root1->right, root2->left);
        }
    };
}

#endif //LEETCODE_LEETCODE101_H
