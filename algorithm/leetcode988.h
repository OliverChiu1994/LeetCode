//
// Created by Oliver on 2025/4/24.
//

#ifndef LEETCODE988_H
#define LEETCODE988_H

#include "../util.h"

namespace LeetCode988 {
    class Solution {
    private:
        vector<string> paths;
        string path;
        int depth = 0;
        int maxDepth = 0;

        string getMinString() {
            string result(maxDepth, 'z');
            for (int i = 0; i < paths.size(); i++) {
                reverse(paths[i].begin(), paths[i].end());
                result = min(result, paths[i]);
            }
            return result;
        }

        void travserse(TreeNode* root) {
            if (root == nullptr) return;
            path.push_back(root->val + 'a');
            depth++;
            if (root->left == nullptr && root->right == nullptr) {
                paths.push_back(path);
                maxDepth = max(maxDepth, depth);
                path.pop_back();
                depth--;
                return;
            }
            travserse(root->left);
            travserse(root->right);
            path.pop_back();
            depth--;
        }
    public:
        string smallestFromLeaf(TreeNode* root) {
            travserse(root);
            cout << maxDepth << endl;
            return getMinString();
        }
    };

    void test() {
        TreeNode* node1 = new TreeNode(0);
        TreeNode* node2 = new TreeNode(1);
        TreeNode* node3 = new TreeNode(2);
        TreeNode* node4 = new TreeNode(3);
        TreeNode* node5 = new TreeNode(4);
        TreeNode* node6 = new TreeNode(3);
        TreeNode* node7 = new TreeNode(4);
        node1->left = node2;
        node1->right = node3;

        node2->left = node4;
        node2->right = node5;

        node3->left = node6;
        node3->right = node7;

        cout << Solution().smallestFromLeaf(node1) << endl;

        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
        delete node7;
    }
}

#endif //LEETCODE988_H
