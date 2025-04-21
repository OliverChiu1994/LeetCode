//
// Created by Oliver on 2025/4/21.
//

#ifndef LEETCODE576_H
#define LEETCODE576_H

#include "../util.h"

namespace LeetCode567 {
    class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            unordered_map<char, int> need;
            for (char c : s1) {
                need[c]++;
            }
            int left = 0, right = 0, count = 0;
            unordered_map<char, int> current;
            while (right < s2.size()) {
                char c = s2[right];
                right++;
                if (need.count(c)) {
                    current[c]++;
                    if (current[c] == need[c]) {
                        count++;
                    }
                }
                // 窗口缩小的时机是子串长度大于目标数组的长度
                while (right - left >= s1.size()) {
                    if (count == need.size()) {
                        return true;
                    }
                    char c = s2[left];
                    left++;
                    if (need.count(c)) {
                        if (current[c] == need[c]) {
                            count--;
                        }
                        current[c]--;
                    }
                }
            }
            return false;
        }
    };

    void test() {
        string s1 = "trinitrophenylmethylnitramine", s2 = "dinitrophenylhydrazinetrinitrophenylmethylnitramine";
        bool res = Solution().checkInclusion(s1, s2);
        print(res);
    }
}

#endif //LEETCODE576_H
