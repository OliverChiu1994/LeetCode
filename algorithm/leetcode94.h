//
// Created by Oliver on 2025/5/19.
//

#ifndef LEETCODE94_H
#define LEETCODE94_H

#include "../util.h"

namespace LeetCode94 {
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            TreeNode* cur = root;
            TreeNode* mostRight = nullptr;
            if (root == nullptr) return res;
            while (cur != nullptr) {
                mostRight = cur->left;
                if (mostRight != nullptr) {
                    while (mostRight->right != nullptr && mostRight->right != cur) {
                        mostRight = mostRight->right;
                    }
                    if (mostRight->right == nullptr) {
                        res.push_back(cur->val);
                        mostRight->right = cur;
                        cur = cur->right;
                    } else {
                        mostRight->right = nullptr;
                        cur = cur->right;
                    }
                } else {
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE94_H
