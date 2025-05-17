//
// Created by Oliver on 2025/5/17.
//

#ifndef LEETCODE102_H
#define LEETCODE102_H

#include <queue>

#include "../util.h"

namespace LeetCode102 {
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if (root == nullptr) {
                return res;
            }
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                vector<int> cur;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    cur.push_back(node->val);
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
                res.push_back(cur);
            }
            return res;
        }
    };
}

#endif //LEETCODE102_H
