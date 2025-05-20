//
// Created by Oliver on 2025/5/20.
//

#ifndef LEETCODE226_H
#define LEETCODE226_H

#include "../util.h"

namespace LeetCode226 {
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            traverse(root);
            return root;
        }

        void traverse(TreeNode* root) {
            if (root == nullptr) return;

            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            traverse(root->left);
            traverse(root->right);
        }
    };
}

#endif //LEETCODE226_H
