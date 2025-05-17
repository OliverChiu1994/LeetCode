//
// Created by Oliver on 2025/5/17.
//

#ifndef LEETCODE107_H
#define LEETCODE107_H

#include <queue>
#include <stack>

#include "../util.h"

namespace LeetCode107 {
    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            if (!root) {
                return res;
            }
            queue<TreeNode*> q;
            q.push(root);
            stack<vector<int>> s;
            while (!q.empty()) {
                vector<int> cur;
                size_t size = q.size();
                for (size_t i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    cur.push_back(node->val);
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
                s.emplace(cur);
            }
            while (!s.empty()) {
                res.emplace_back(s.top());
                s.pop();
            }
            return res;
        }
    };
}

#endif //LEETCODE107_H
