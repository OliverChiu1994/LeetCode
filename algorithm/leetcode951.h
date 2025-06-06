//
// Created by zhaogan on 2025/6/6.
//

#ifndef LEETCODE_LEETCODE951_H
#define LEETCODE_LEETCODE951_H

#include "../util.h"

namespace LeetCode951 {
    class Solution {
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            if (root1 == nullptr) return root2 == nullptr;
            if (root2 == nullptr) return false;
            if (root1->val != root2->val) return false;
            if (flipEquiv(root1->left, root2->left)) return flipEquiv(root1->right, root2->right);
            if (flipEquiv(root1->left, root2->right)) return flipEquiv(root1->right, root2->left);
            return false;
        }
    };
}

#endif //LEETCODE_LEETCODE951_H
