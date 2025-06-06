//
// Created by zhaogan on 2025/6/6.
//

#ifndef ALGORITHM_LEETCODE124_H
#define ALGORITHM_LEETCODE124_H

#include "../util.h"

namespace LeetCode124 {
    class Solution {
    private:
        int res = INT_MIN;
    public:
        int maxPathSum(TreeNode* root) {
            maxPath(root);
            return res;
        }

        int maxPath(TreeNode* root) {
            if (root == nullptr) return 0;
            int l = max(0, maxPath(root->left));
            int r = max(0, maxPath(root->right));
            res = max(l + r + root->val, res);
            return max(0, max(l, r) + root->val);
        }
    };
}

#endif //ALGORITHM_LEETCODE124_H
