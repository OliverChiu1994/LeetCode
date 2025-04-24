//
// Created by Oliver on 2025/4/23.
//

#ifndef LEETCODE257_H
#define LEETCODE257_H

#include "../util.h"

namespace LeetCode257 {
    class Solution {
    private:
        vector<vector<int>> res;
        vector<int> curPath;
    public:
        void traverse(TreeNode* root) {
            if (root == nullptr) return;
            curPath.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                res.push_back(curPath);
                curPath.pop_back();
                return;
            }

            traverse(root->left);
            traverse(root->right);
            curPath.pop_back();
        }

        string getPath(vector<int> path) {
            string res;
            for (int i = 0; i < path.size(); i++) {
                res += to_string(path[i]);
                if (i != path.size() - 1) {
                    res += "->";
                }
            }
            return res;
        }

        vector<string> binaryTreePaths(TreeNode* root) {
            traverse(root);
            print();
            vector<string> res;
            for (int i = 0; i < res.size(); i++) {
                stringRes.push_back(getPath(res[i]));
            }
            return stringRes;
        }
    };
}

#endif //LEETCODE257_H
