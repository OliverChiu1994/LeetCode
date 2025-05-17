//
// Created by Oliver on 2025/5/16.
//

#ifndef LEETCODE111_H
#define LEETCODE111_H

#include <queue>

#include "../util.h"

namespace LeetCode111 {
    class Solution {
    public:
        // bfs
        int minDepth(TreeNode* root) {
            int depth = 0;
            if (root == nullptr) return 0;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                depth++;
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left == nullptr && node->right == nullptr) {
                        return depth;
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }
            }
            return depth;
        }

        // dfs
        int minDepthValue = INT_MAX;
        int depth = 0;
        int minDepth2(TreeNode* root) {
            if (root == nullptr) return 0;

            traverse(root);
            return minDepthValue;
        }

        void traverse(TreeNode* root) {
            if (root == nullptr) return;
            depth++;
            if (root->left == nullptr && root->right == nullptr) {
                minDepthValue = min(minDepthValue, depth);
            }
            traverse(root->left);
            traverse(root->right);
            depth--;
        }
    };
}

#endif //LEETCODE111_H
