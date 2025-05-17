//
// Created by Oliver on 2025/5/17.
//

#ifndef LEETCODE637_H
#define LEETCODE637_H

#include <queue>

#include "../util.h"

namespace LeetCode637 {
    class Solution {
    public:
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> res;
            if (root == nullptr) {
                return res;
            }
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                double sum = 0;
                size_t size = q.size();
                for (size_t i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    sum += node->val;
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
                res.push_back(sum / size);
            }
            return res;
        }
    };
}

#endif //LEETCODE637_H
