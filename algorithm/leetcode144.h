//
// Created by Oliver on 2025/5/19.
//

#ifndef LEETCODE144_H
#define LEETCODE144_H

#include <stack>

#include "../util.h"

namespace LeetCode144 {
class Solution {
public:
    // 方法一：递归
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        preorder2(root);
        return res;
    }

    void preorder(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void preorder2(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right != nullptr) s.push(cur->right);
            if (cur->left != nullptr) s.push(cur->left);
        }
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        TreeNode* cur = root;
        TreeNode* mostRight = root;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (cur->left != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    // 第一次到达
                    res.push_back(cur->val);
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    // 第二次到达
                    mostRight->right = nullptr;
                    cur = cur->right;
                }
            } else {
                cur = cur->right;
                res.push_back(cur->val);
            }
        }
        return res;
    }
};
}

#endif //LEETCODE144_H
