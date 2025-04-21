//
// Created by Oliver on 2025/4/18.
//

#ifndef LEETCODE344_H
#define LEETCODE344_H

#include "../util.h"

namespace LeetCode344 {
    class Solution {
    public:
        void reverseString(vector<char>& s) {
            int left = 0, right = s.size() - 1;
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
    };

    inline void test() {
        vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
        Solution solution;
        solution.reverseString(s1);
        print(s1);
    }
}

#endif //LEETCODE344_H
