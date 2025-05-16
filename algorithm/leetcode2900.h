//
// Created by Oliver on 2025/5/15.
//

#ifndef LEETCODE2900_H
#define LEETCODE2900_H

#include "../util.h"

namespace LeetCode2900 {
    class Solution {
    public:
        vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
            vector<int> indexs;
            if (groups.empty()) return vector<string>();
            int cur = groups[0];
            indexs.push_back(0);
            for (int i = 1; i < groups.size(); i++) {
                if (groups[i] != cur) {
                    cur = groups[i];
                    indexs.push_back(i);
                }
            }
            vector<string> res;
            for (int i = 0; i < indexs.size(); i++) {
                res.push_back(words[indexs[i]]);
            }
            return res;
        }
    };
}

#endif //LEETCODE2900_H
