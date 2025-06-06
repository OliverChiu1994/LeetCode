//
// Created by Oliver on 2025/6/4.
//

#ifndef LEETCODE297_H
#define LEETCODE297_H

#include "../util.h"

namespace LeetCode297 {
    class Codec {
    private:
        const char SEP = ',';
        const string NULL_STR = "NULL";
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string res = "[";

            res += "]";
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data.empty()) {
                return nullptr;
            }
            stringstream ss(data);
            string item;
            if (!getline(ss, item, SEP) || item == NULL_STR) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(stoi(item));
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                size_t size = q.size();
                for (size_t i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (!getline(ss, item, SEP) || item == NULL_STR) {
                        node->left = nullptr;
                    } else {
                        TreeNode* left = new TreeNode(stoi(item));
                        node->left = left;
                        q.push(left);
                    }

                    if (!getline(ss, item, SEP) || item == NULL_STR) {
                        node->right = nullptr;
                    } else {
                        TreeNode* right = new TreeNode(stoi(item));
                        node->right = right;
                        q.push(right);
                    }
                }
            }
            return root;
        }
    };
}

#endif //LEETCODE297_H
