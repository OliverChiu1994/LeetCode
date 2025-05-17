//
// Created by zhaogan on 2025/5/13.
//

#ifndef LEETCODE_LEETCODE3335_H
#define LEETCODE_LEETCODE3335_H

#include "../util.h"

namespace LeetCode3335 {
    class Solution {
    public:
        int lengthAfterTransformations(string s, int t) {
            const int MOD = 1e9 + 7;
            int res = s.size();
            int time = t / 26;
            int extra = t % 26;
            for (int i = 0; i < s.size(); i++) {
                int diff = 'z' - s[i];
                if (extra > diff) {
                    res++;
                }

            }
        }
    };
}

#endif //LEETCODE_LEETCODE3335_H
