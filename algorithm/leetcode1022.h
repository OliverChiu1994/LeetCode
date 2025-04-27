//
// Created by Oliver on 2025/4/27.
//

#ifndef LEETCODE1022_H
#define LEETCODE1022_H

#include "../util.h"

namespace LeetCode1022 {
    // 方法1，遍历
    class Solution {
    private:
        vector<int> path;
        vector<vector<int>> paths;
    public:
        void dfs(TreeNode* root) {
            if (root == nullptr) return;
            path.emplace_back(root->val);
            if (root->left ==nullptr && root->right == nullptr) {
                paths.emplace_back(path);
            }
            dfs(root->left);
            dfs(root->right);
            path.pop_back();
        }

        int sumRootToLeaf(TreeNode* root) {
            dfs(root);
            int sum = 0;
            for (int i = 0; i < paths.size(); ++i) {
                int num = 0;
                for (int j = 0; j < paths[i].size(); ++j) {
                    num = num * 2 + paths[i][j];
                }
                sum += num;
            }
            return sum;
        }
    };

    // 方法2 递归
    class Solution2 {
    public:
        int process(TreeNode* root, int val) {
            if (root == nullptr) return 0;
            val = (val << 1) | root->val;
            if (root->left == nullptr && root->right == nullptr) {
                return val;
            }
            return process(root->left, val) + process(root->right, val);
        }

        int sumRootToLeaf(TreeNode* root) {
            return process(root, 0);
        }
    };

    void test() {
        TreeNode* n1 = new TreeNode(1);
        TreeNode* n2 = new TreeNode(0);
        TreeNode* n3 = new TreeNode(1);
        TreeNode* n4 = new TreeNode(0);
        TreeNode* n5 = new TreeNode(1);
        TreeNode* n6 = new TreeNode(0);
        TreeNode* n7 = new TreeNode(1);

        n1->left = n2;
        n1->right = n3;

        n2->left = n4;
        n2->right = n5;

        n3->left = n6;
        n3->right = n7;

        cout << Solution2().sumRootToLeaf(n1) << endl;

        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete n5;
        delete n6;
        delete n7;
    }

}

#endif //LEETCODE1022_H
