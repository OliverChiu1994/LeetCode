//
// Created by Oliver on 2025/5/20.
//

#ifndef LEETCODE116_H
#define LEETCODE116_H

#include <queue>

#include "../util.h"

namespace LeetCode116 {
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };

    class Solution {
    public:
        // 方法一：层序遍历
        Node* connect2(Node* root) {
            if (root == nullptr) return root;
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                Node* pre = nullptr;
                for (int i = 0; i < size; i++) {
                    Node* node = q.front();
                    q.pop();
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }

                    if (i == 0) {
                        pre = node;
                    } else {
                        pre->next = node;
                        pre = node;
                    }
                }
            }
            return root;
        }

        // 方法二：遍历
        Node* connect(Node* root) {
            traverse(root->left, root->right);
            return root;
        }

        void traverse(Node* node1, Node* node2) {
            if (node1 == nullptr || node2 == nullptr) return;

            node1->next = node2;

            traverse(node1->left, node1->right);
            traverse(node1->right, node2->left);
            traverse(node2->left, node2->right);
        }
    };
}

#endif //LEETCODE116_H
