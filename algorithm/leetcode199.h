//
// Created by Oliver on 2025/4/24.
//

#ifndef LEETCODE199_H
#define LEETCODE199_H

#include <queue>

#include "../util.h"

namespace LeetCode199 {
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> result;
            if (root == nullptr) {
                return result;
            }
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                auto head = q.front();
                for (int i = 0; i < size; i++) {
                    auto node = q.front();
                    q.pop();
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                }
                result.push_back(head->val);
            }
            return result;
        }

        int depth = 0;
        vector<int> result;
        void traverse(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            depth++;
            if (result.size() < depth) {
                result.push_back(root->val);
            }
            traverse(root->right);
            traverse(root->left);
            depth--;
        }

        vector<int> rightSideView_dfs(TreeNode* root) {
            result.clear();
            depth = 0;
            traverse(root);
            return result;
        }
    };

    void test() {
        TreeNode* node1 = new TreeNode(1);
        TreeNode* node2 = new TreeNode(2);
        TreeNode* node3 = new TreeNode(3);
        node1->left = node2;
        node1->right = node3;

       print(Solution().rightSideView(node1));

        delete node1;
        delete node2;
        delete node3;
    }
}

#endif //LEETCODE199_H
