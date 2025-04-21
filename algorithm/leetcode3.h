//
// Created by Oliver on 2025/4/21.
//

#ifndef LEETCODE3_H
#define LEETCODE3_H

#include "../util.h"

namespace LeetCode3 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> window;
            int left = 0, right = 0, len = 0;
            while (right < s.size()) {
                char c = s[right++];
                if (!window.count(c)) {
                    window.insert(c);
                    // 注意上面的right已经+1了，所以这里取长度的时候不能加1
                    len = max(len, right - left);
                    continue;
                }
                // 有重复元素
                while (left <= right) {
                    char c1 = s[left++];
                    if (c1 != c) {
                        window.erase(c1);
                    } else {
                        break;
                    }
                }
            }
            return len;
        }
    };

    void test() {
        string s = "pwwkew";
        cout << Solution().lengthOfLongestSubstring(s) << endl;
    }
}

#endif //LEETCODE3_H
