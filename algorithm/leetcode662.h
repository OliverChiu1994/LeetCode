//
// Created by Oliver on 2025/4/27.
//

#ifndef LEETCODE662_H
#define LEETCODE662_H

#include <queue>

#include "../util.h"

namespace LeetCode662 {
    class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            unsigned long long res = 1;
            vector<pair<TreeNode *, unsigned long long>> arr;
            arr.emplace_back(root, 1L);
            while (!arr.empty()) {
                vector<pair<TreeNode *, unsigned long long>> tmp;
                for (auto &[node, index] : arr) {
                    if (node->left) {
                        tmp.emplace_back(node->left, index * 2);
                    }
                    if (node->right) {
                        tmp.emplace_back(node->right, index * 2 + 1);
                    }
                }
                res = max(res, arr.back().second - arr[0].second + 1);
                arr = move(tmp);
            }
            return res;
        }
    };

    void test() {
        TreeNode* n1 = new TreeNode(1);
        TreeNode* n2 = new TreeNode(3);
        TreeNode* n3 = new TreeNode(2);
        TreeNode* n4 = new TreeNode(5);

        n1->left = n2;
        n1->right = n3;
        n2->left = n4;

        cout << Solution().widthOfBinaryTree(n1) << endl;

        delete n1;
        delete n2;
        delete n3;
        delete n4;
    }
}

#endif //LEETCODE662_H
