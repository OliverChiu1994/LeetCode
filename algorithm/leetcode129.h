//
// Created by Oliver on 2025/4/24.
//

#ifndef LEETCODE129_H
#define LEETCODE129_H

#include "../util.h"

namespace LeetCode129 {
    class Solution {
    private:
        vector<int> path;
        vector<vector<int>> pathVec;
        int sum = 0;
    public:
        void traverse(TreeNode* root) {
            if (root == nullptr) return;
            path.emplace_back(root->val);

            if (root->left == nullptr && root->right == nullptr) {
                pathVec.emplace_back(path);
                // 这一步至关重要
                path.pop_back();
                return;
            }
            traverse(root->left);
            traverse(root->right);
            path.pop_back();
        }
        void getSum() {
            for (int i = 0; i < pathVec.size(); i++) {
                int cur = 0;
                for (int val : pathVec[i]) {
                    cur = cur * 10 + val;
                }
                sum += cur;
            }
        }

        int sumNumbers(TreeNode* root) {
            traverse(root);
            getSum();
            return sum;
        }
    };

    void test() {
        TreeNode* node1 = new TreeNode(1);
        TreeNode* node2 = new TreeNode(2);
        TreeNode* node3 = new TreeNode(3);
        node1->left = node2;
        node1->right = node3;

        cout << Solution().sumNumbers(node1) << endl;

        delete node1;
        delete node2;
        delete node3;
    }
}

#endif //LEETCODE129_H
